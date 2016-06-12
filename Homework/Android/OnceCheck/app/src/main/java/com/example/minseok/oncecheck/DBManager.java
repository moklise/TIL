package com.example.minseok.oncecheck;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.widget.Toast;

/**
 * Created by minseok on 2016-06-12.
 */
// DB HELPER
public class DBManager extends SQLiteOpenHelper {
    Context context;
    SQLiteDatabase db;
    Cursor cursor;

    // DATABASE name
    //private static final String DATABASE_NAME = "/sdcard/SQLiteDB/productDB.db";
    private static final String DATABASE_NAME = "productDB.db";
    // DATABASE version
    private static final int DATABASE_VERSION = 1;
    // TABLE name
    private static final String CLASS_TABLE_NAME = "classTable";
    private static final String BASE_TABLE_NAME = "baseTable";

    // OpenHelper 생성자(context, DB name, cursor, DB version)
    public DBManager(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
        this.context = context;
    }

    /* 데이터베이스 Create
       - 생성자에서 넘겨받은 이름의 DB와 버전의 DB가 존재하지 않을 때 호출됨
       - 새로운 데이터베이스를 생성할 때 사용
     */



    @Override
    public void onCreate(SQLiteDatabase db) {
        /* 테이블을 생성하기 위해 SQL문을 작성하여 execSQL 문 실행
           - CREATE TABLE 테이블명 (컬럼명 타입 옵션);
        */
        db.execSQL("CREATE TABLE " + BASE_TABLE_NAME + "( key TEXT PRIMARY KEY, value TEXT);");
        db.execSQL("CREATE TABLE " + CLASS_TABLE_NAME + "( name TEXT PRIMARY KEY, dayOfWeek TEXT, memo TEXT);");
        Toast.makeText(context, "onCreate() 메소드 호출", Toast.LENGTH_LONG).show();
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        Toast.makeText(context,"onUpgrade() 메소드 호출", Toast.LENGTH_LONG).show();
        db.execSQL("DROP TABLE IF EXISTS " + BASE_TABLE_NAME);
        db.execSQL("DROP TABLE IF EXISTS " + CLASS_TABLE_NAME);
        onCreate(db);
    }

    //테이블의 레코드(행) Insert
    public void b_insert(String _key, String _value) {
        db = getWritableDatabase();
        db.execSQL("INSERT INTO " + BASE_TABLE_NAME + " VALUES('"+ _key + "', '" + _value+"');");
        db.close();
    }

    public void c_insert(String _className, String _classTime, String _classMemo) {
        db = getWritableDatabase();
        db.execSQL("INSERT INTO " + CLASS_TABLE_NAME + " VALUES('"+ _className + "', '" + _classTime
                + "', '" + _classMemo + "');");
        db.close();
    }

    //테이블의 레코드 Update
    public void b_update(String productName, String price) {
        db = getWritableDatabase();//DB를 read/write 모드로 open
        db.execSQL("UPDATE " + BASE_TABLE_NAME + " SET price = " + price + " WHERE productName = '"
                + productName + "';");
        db.close();//DB close
    }

    public void c_update(String productName, String price) {
        db = getWritableDatabase();//DB를 read/write 모드로 open
        db.execSQL("UPDATE " + BASE_TABLE_NAME + " SET price = " + price + " WHERE productName = '"
                + productName + "';");
        db.close();//DB close
    }

    //테이블의 레코드 Delete
    public void b_delete(String productName) {
        db = getWritableDatabase();//DB를 read/write 모드로 open
        db.execSQL("DELETE FROM " + BASE_TABLE_NAME + " WHERE productName = '" + productName + "';");
        db.close();
    }

    //테이블의 레코드 Delete
    public void c_delete(String productName) {
        db = getWritableDatabase();//DB를 read/write 모드로 open
        db.execSQL("DELETE FROM " + CLASS_TABLE_NAME + " WHERE productName = '" + productName + "';");
        db.close();
    }

    //조건에 맞는 레코드 Select
    public String b_select(String key) {
        db = getReadableDatabase();//DB를 read 전용 모드로 open
        String str = "";

        /* 레코드를 검색하기 위해 SELECT 문을 작성하여 rawQuery 문 실행
           - SELECT 검색할 컬럼 FROM 테이블명 WHERE 조건;
           - 조건에 맞는 레코드를 검색할 때 사용
           - 테이블에서 조건에 맞는 레코드를 검색하여 cursor 객체에 저장
             (rawQuery()는 검색 결과를 cursor 객체에 반환)
         */
        cursor = db.rawQuery("SELECT key, value FROM " +  BASE_TABLE_NAME
                + " WHERE key LIKE '"
                + key + "%'", null);

        /* 반복문을 사용하여 cursor 객체에 있는 레코드의 컴럼값을 추출
           - moveToNext()는 커서를 다음 레코드로 이동시키는 메소드로, 만약 레코드가 없으면 false 반환
           - 레코드의 컬럼값을 추출할 때는 컬럼의 타입에 따라 getInt(컬럼index), getString(컬럼index)
             등의 메소드 사용
         */

        if(cursor.moveToNext()){
            str = cursor.getString(1);
        }
        cursor.close();
        db.close();

        return str;
    }

    public String c_select(String productName) {
        db = getReadableDatabase();//DB를 read 전용 모드로 open
        String str = "";

        /* 레코드를 검색하기 위해 SELECT 문을 작성하여 rawQuery 문 실행
           - SELECT 검색할 컬럼 FROM 테이블명 WHERE 조건;
           - 조건에 맞는 레코드를 검색할 때 사용
           - 테이블에서 조건에 맞는 레코드를 검색하여 cursor 객체에 저장
             (rawQuery()는 검색 결과를 cursor 객체에 반환)
         */
        cursor = db.rawQuery("SELECT _id, productName, price FROM " +  CLASS_TABLE_NAME
                + " WHERE productName LIKE '"
                + productName + "%'", null);

        /* 반복문을 사용하여 cursor 객체에 있는 레코드의 컴럼값을 추출
           - moveToNext()는 커서를 다음 레코드로 이동시키는 메소드로, 만약 레코드가 없으면 false 반환
           - 레코드의 컬럼값을 추출할 때는 컬럼의 타입에 따라 getInt(컬럼index), getString(컬럼index)
             등의 메소드 사용
         */
        while (cursor.moveToNext()) {
            str += cursor.getInt(0) // _id
                    +  " : 제품명: "
                    + cursor.getString(1) // productName
                    + ", 가격: "
                    + cursor.getInt(2) // price
                    + "\n";
        }
        cursor.close();
        return str;
    }

    // 테이블에 있는 전체 레코드 Select - 전체 검색
    public String b_printData() {
        db = getReadableDatabase();
        String str = "";

        // SELECT * FROM 테이블명 null;
        cursor = db.rawQuery("SELECT * FROM " +  BASE_TABLE_NAME, null);

        while (cursor.moveToNext()) {
            str += cursor.getInt(0)
                    + " : 제품명: "
                    + cursor.getString(1)
                    + ", 가격: "
                    + cursor.getInt(2)
                    + "\n";
        }
        cursor.close();
        return str;
    }

    public String c_printData() {
        db = getReadableDatabase();
        String str = "";

        // SELECT * FROM 테이블명 null;
        cursor = db.rawQuery("SELECT * FROM " +  CLASS_TABLE_NAME, null);

        while (cursor.moveToNext()) {
            str += ""
                    + cursor.getString(0)
                    + " _ "
                    + cursor.getString(1)
                    + " _ "
                    + cursor.getString(2)
                    + "\n";
        }
        cursor.close();
        return str;
    }
}//end of file

