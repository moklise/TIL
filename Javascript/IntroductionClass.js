function Vehicle ( numOfWheel, numOfSeat ){
	this.wheel = numOfWheel;
	this.seat = numOfSeat;
}

Vehicle.prototype.getInfo = function(){
	console.log(this.wheel + this.seat);
}

var bike = new Vehicle(2,1);