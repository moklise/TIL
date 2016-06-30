#Computational Drug Repositioning<br/>: From Data to Therapeutics
##### VOULUME 93 NUMBER4 | APRIL 2013 | www.nature.com/cpt
<hr/>

### Genetics

1. Human genetics studies offer one of the strongest lines of evidence to connect specific genes to specific human diseases.

	> 인간 유전자 연구는 특정 유전자와 특정 질병간의 연결이 있음을 알리는 강력한 단서를 제공한다.

2. Recent technological advances such as next-generation sequencing have accelerated the discovery of gene-disease associations by drastically reducing the cost of whole-exome sequencing.
	> next-generation sequencing 같은 최근 기술 발전은 과감하게 모든 exon sequencing의 비용을 줄임으로써 유전자-질병 관계의 발견을 가속화하고있다.

	> 예시로 아데노신 신진대사에서 성인 동맥 석화화의 형성과 관련된 효소의 정보를 담고있는 유전자인 NTE5의 식별이 존재한다.
	> 이 효소가 발견되었을때
	> 이 경우, 항혈전제 ( 혈소판의 혈액응고 작용 억제제 )가 처방되는데
	> 아데노신의 재흡수가 억제되어, 잠재적으로 도움이 되기 때문이다.
	 많은 단성 장애인들은, 원인유전자에서의 돌연변이는 단백질 결과물의 발생에 지장을 준다.
	 그러므로 만약 그 타겟이 질병 유전자면 Activator가 필요해질 가능성이 높으므로
	 Activator가 활성화되면 그 Target 이 a disease gene 임을 알 수 있다.
     
     ```동맥 석화화 형성과 관련된 효소가 발견됨 -> 동맥 석화화 형성과 관련된 효소의 생성을 막기위해 아데노신의 흡수를 막음 -> 아데노신의 생성을 위해 Activator가 필요하게 됨. -> ????```
	
3. Genome-wide association studies (GWAS) have shown the association between genetic variants and polygenic diseases, resulting in the identification of genes proximal to these vriants as being linked to numerous complex disease.

	> GWAS는 소유전자 질병과 유전학적 변종 사이에서의 연관이 있다는것을 보여주었고. 그 결과 많은 복합적인 질병들과 연결되어이 있다는 것이 밝혀졌다.
	Francis Collins 이 US NCATS 창설 당시 발표 내용에서, 이미 시장에 나온 Drug와 연관이 있는 type 2 diabetes를 위해 44 GAWS loci 중 6개를 관찰했다고 한다. 이 관찰은 GWAS-identified genes이 작은 분자들과 생물학에 의해 쉽게 다룰 수 있는 가능성이 있다는 것을 말해주었다. 이 studies 들은 인간 유전체학과 약리학의 집합이 더 나은 drug target의 몇몇을 주목할수도 있다 라는 것을 말해준다.
    
    > 모든 155개의 유전자들은 이미 개발중이거나 시장에나온 상품들에 의해 being targeted 되고 식별되어있다.
    
    > 그중에서 92개의 타겟 유전자들에 약 징후는 GWAS에 의해 식별된 질병특성과는 다르다.
    이 상황은 92개의 gene produts을 타겟으로 하고있는 drugs 이 GWAS에 의해 새로운 질병 특성으로 평가 되어질수 있다는 것을 의미한다.
    
4. It is evident that the gene-disease association identified by GWAS inform possible drug repositioning opportunities.
	> GWAS에 의해 식별된 gene-disease 연관은 가능한 drug repositioning의 기회를 알려주고있다.

	> 그러나 GWAS 데이터를 사용하는데 있어서 어려움이 존재한다.
	GWAS 정보를 단독으로 사용했을때, 요구되는 치료영향의 방향의 부재는 개시자나 억제자가 필요한지 아닌지 알아내는것을 어렵게 하고있다.
    게다가 단성의 장애는 대부분 기능문제에 의해 발생되기 때문에,
    Repositioning methods들은 식별된 유전자의 negative regulator를 대상으로 하거나 dipyrida mole 같은 경우처럼 기능의 손실의 기계론적인 영향을 상쇄 시키거나 하는 약에 집중해야 한다.


### Other methods

1. The various stages of drug discovery produce additional data relevant to repurposing (Figue 3).

	> 약 발견의 여러가지 단계는 repurposing과 관련된 추가적인 데이터들을 생성한다.
	잠재적인 약 타겟들을 위해 기계론적인 이해와 질병의 분류를 개선하는데 있어서 엄청난 노력을 쏟아왔다
    그러므로 This target discovery field는 네트워크에서 처리되어져온 genetics, signaling pathwats, and PPI의 데이터들이 풍부하다.
    새로운 징후들은 질병간의 similarities가 평가되어지면서 이 데이터로부터 예견되어져온다.
    

##### Pathways and networks ( disease similarity )

 > ```질병들은 서로 공유되는 특성으로 다른 질병들과 네트워크로 연결될 수 있다.```
	For example, 한 연구에서는 질병들을 단백질 상호작용 모듈과 함께 연결할 수 있었다.
    Disease similarity 는 기본 pathways 나 이러한 모듈을 사용하며 하나의 질병이 다른 질병으로 리포지션하는데에 사용되어 질 수 있었다.
```    Chiang and Butte 는 "guilt by association"이라고 불리우는  다른 disease similarity approach 를 사용했다.```
```    이 접근은 질병들 중 하나에 승인이
    연구자들은 이 방법을 사용하는게 가설과 연관된 의학적 시도로 이끌 가능성이 12배 높다는 걸 보여주었다.```
    PREDICT같은 통합 메소드들은 drug X와 disease Y가 각자 잘 알려진 drug-disease 관계와 비슷하다면,
    X 는 Y를 치료할 수 있다고 평가되어진다.
    PREDICT는 cross-validation 을 사용했을때 높은 통계적 정확성을 보인다.
    ```그러나, 이 예측의 Black-box 형태는 아마 실험적 검증에서 어려움을 느낄 것이다 ```
    ( 원인과 결과만 알고 그 과정을 자세히 모르므로. )
   ``` 개의치않고, 만약 이 기술의 정확성이 높다는 것이 증명된다면, 이 기술은 더 널리 사용될 것이고, 실험적으로 	입증 될 것이다.```
    
##### Screening
> 많은 양의 Screening results 는 리포지셔닝 가설의 많은 근원일 것이다.
screening 같은 자원을 구할 수 있는 곳은 PubChem 이라는 곳인데,
screen으로부터 표현형적인 것들을 많은 결과를 가지고 있는 곳이다.
만약 drug나 가깝게 관계된 분자가 표현형에서 활성화 되어있다면, 그것은 리포지셔닝에서의 가장 단순한 케이스를 보여주는것이고,그것은 그 표현형과 관련된 질병에서 테스트가 되어질 것이다.
PubChem bioassay data는 이미 부정적인 약 반응에 대해 예견하는데에 사용되었다.
비슷한 접근으로 질병의 징후를 예측하는 것 또한 가능하다

? Screening

##### Off-target effects


> 한번 혼합물이 target에 결합되는것으로써 식별되어진다면, 그 관계된 target 들과 compound 들은 구조적 알고리즘을 통해 예견되어 질 것이다. 잠재적인 대상들은 ligand-binding pockets의 similarites를 통해 식별되어질수있다.
> ( target 과 coumpound 의 관계를 구조적 알고리즘으로 파악하고, 그와 비슷한 구조를 가지는 것들은 Potential Target이 된다. )
> 이러한 접근을 사용해서, Mycobacterium tuberculosis 의 the enoyl-acyl carrier protein 는 rat Catechol-o-methyltransferase와 비슷한 구조를 가지는데, 이는 파킨슨 병의 치료제인 entacapone의 대상이다. 
그 Compound  들은 enoyl-acyl carrier protein reductase의 활동과 pathogen의 성장을 막는다고 밝혀졌다.
모든 단백질 구조가 밝혀진건 아니기때문에,  인상적이게 30개의 신기한 drug-target 예측중 23개의 예측을 검증하고있는 ligands 의 생리학적 속성이나 구조적 속성을 활용하는 메소드들이 개발되고있다.

> Compound 와 protein structure 의 지식을사용하는 접근을 molecular docking 이라고 한다.
> 이 molecular docking은 ligand-protein 상호작용의 강도 ( 얼마나 작용하나 )를 평가한다.
> 이러한 접근은 성공적으로 항 HIV제인 haloperidol을 발견해냈다.
> 왜냐하면 이 compound는 또한 대부분 조건에서 일반적으로 결합되는 대상에 결합하기때문에,
> 항전염 drugs와 인간 targets사이의 리포지셔닝은 off-target methods의 가장 효과적인 응용이될 가능성이 크다.

##### In vivo
> 대상으로 지정된 돌연변이를 사용하는 Invivo phenotypic screening은 표현형과 함께 유전자를 연관시키는데 널리 사용되어왔다.
> The Mouse Phenome Database 는 여러 인간 질병과 관련된 1400개의 표현형 측정 데이터를 가지고 있다.
> 추론에 의해서, 이 표현형은 질병과 질병과 함께 유전자 생성물을 타겟으로 하는 drug 과 함께 유전자와 연관되어있다.
> 표준 포유류 표현형 데이터를 발생시키는 국제적 협회의 설립은 이 표현형 데이터의 활용을 도와줄 것이다.
> 우리는 이러한 데이터들이 발견한 결과물을 비록 in vivo model 에서 human model 으로 번역하는것은 어려울 것으로 보이지만, 미래 리포지셔닝 노력을 증가하는 역할을 할 것이다.

##### Therapeutic effects
 
> 비록 환자에서 약리학적 효과의 의학적 관찰에 근거한 성공적인 drug repositioning 사례는 보고되었지만, 리포지셔닝의 체계적인 사용을 통한 사례는 적다.
> 이것은 아마 publicly 사용할 수 있는 의학시도 데이터의 부족의 결과가 아닐까 한다.
> 그러나 이러한 의학적 시도 데이터가 점점더 순조롭게 사용되어 질수있게 되고있다.

##### Observational studies, EHRs, and social media
1. As drugs progress into the clinic, they generate clinical data that can be analyzed for repositioning oppotunities. The almost incomprehensible volume and complexity of EHRs present opportunities that could well be the source of the next great advances in drug repositioning.
> 약이 치료로써의 기능을 함으로써, 이 약들은 리포지셔닝 기회를 위해 분석되어질수있는 의학적 데이터를 만든다. 이 데이터들은 약이 인가되어야 얻을 수 있는 현실세계 관찰적 데이터이기때문에 소량이다.
> EHRs의 이해할 수 없는 양과 복잡성은 드러그 리포지셔닝에서의 다음 발전의 원천이 될 수 있음을 보여준다. 
> Online self-reported patient data는 근위축성의 과정에서 리튬의 영향을 테스트할수 있도록 분석되어진다.
> 부작용은 언급되어질 수 있으며, 신호들을 감지하는 메소드들이 발생할 수 있다.
> 이러한 방법들은 결국 다른 소셜 미디어 처럼 이익효과를 감지하는데까지 연장될 수 있다.
> 주로 부작용을 감지하는 Observational Medical Outcomes Partnership의 부분으로써 평가되고 개발된 메소드들은 언젠가 긍정적 약 효과의 발견으로서 이어질 수 있다.
> 랜드마크 연구는 체계적으로 부작용과 약의 관계를 에측하며, 그 후 EHR data를 이용하여 예측의 몇 부분을 검증한다.
> 또한, 이러한 관찰된 의학적인 부작용들을 발견하려고자 하는 노력은 약을 리포지셔닝하는데 큰 기회를 제공할 것이다.


2. Experimental validation and independent validation add verifity to computational hypothesis.
> 실험적인 검증과 독립적인 검증은 computational 가설에 타당성을 부여한다
> 출판된 문서들로부터 데이터들을 mining하는 노력은 가설을 뒷받침하는 실험적 약 연구나 case reports를 identify할 수 있다.
> 
3. Without a computational hypothesis, a preclinical or clinical hypothesis may not be actionable; however, once the two are put together, they can accelerate the path toward a clinical trial.
4. 
> 다른 경우에서는 내부적 임상전과 의학적인 관찰은 가설을 강화시킬 수 있고, 심지어는 가설이 사실임을 입증할 수 있다.
> Computational hypothesis없이, 임상전이나 임상의 가설들은 절대 시작될 수 없을 것이다.
> 그러나 Experimental validation and independent validation 이 함께 주어진다면, 임상실험을 진행할 수 있도록 진행상황을 가속화 할 수 있다.


###Conclusion

1. It is also indisputable that repositioning is a key value driver.

	> 리포지셔닝은 명백히 가치를 창출할 수 있는 방법임.

2. Both the Medical Rearch Council in the United Kingdome and the National Institutes of Health in the United States have announced public-private partnership to repurpose failed pipeline drugs.

	> 영국의 MRC 와 미국의 NIH같은 경우 실패한 약들의 리포지셔닝을 진행하기 위하여 <br/>public-private 	   partnerships을 발표 한바 있다. 또한 The National Institutes of Health's National Center for Advancing Translational Sciences 는 3800개의 승인되고 시험용으로 사용되고있는 혼합물 정보를 가지고 있다.
	> 이 정보들은 새 실험적 데이터를 발생시키거나 기존에 있던 지식들을 통합시키면 리포지셔닝의 최고의 자원이 	될 것으로 보인다.

3. The rise of translational bioinformatics as a discipline suggests that the field of computational biology is maturing and is perhaps more ready than ever to develop solutions that will have a beneficial impact on human health in the near term.

	> Translational Bioinformatics의 부상은 이 계산적 biolody 분야가 더욱 성숙해지고, 어느때보터 빠른 시일내에 Human health에 큰 영향을 줄 수 있는 Solution을 개발할 준비가 되어있음을 말해주고 있다.

