# A survey of current trends in computational drug repositioning
### Jiao Li, Si Zheng, Bin Chen, Atul j.Butte, S. Joshua Swamidass and Zhiyoung Lu
<hr/>

#### Network analysis
1. Intro
	> Network-based analysis is used strategy for computational drug repositioning.
	> Previous studies have suggested that drug-target network, drug-drug network, drug-disease network, protein interaction network, transcriptional networks and signaling networks are useful in the identification of therapeutic targets of characteristics of drug targets, thus providing new opportunities for drug discovery or repositioning.

2. Li et al
	> 비슷한 약들의 관계를 통해 이미 존재하는 약의 새로운 징후를 찾는 the bipartite drug-target network method를 개발함.
	> 이 the bipartite network model 에선, Drug pair similarity는 drug chemical structure similarity와 common drug targets 그리고 그들의 interaction을 포함하고있다.
	> 과거의 성공을 기반으로 같은 저자는 이미 존재하는 약의 새로운 의학적 사용을 발견하기 위해 CauseNet 이라는 것을 만들었다.
	> 이 CauseNet 이란 gene, disease and drug target의 다계층 패스웨이 이다.
	> 이 CauseNet에선 각 chain의 실질적 약 전환 가능성은 잘 알려진 약-질병 치료 연관관계를 기반으로 평가되는 방식으로 사용하고 있다.
3. Wu et al
	> 이 분은 가깝게 연결된 drug-disease 모듈을 찾아내기 위하여 drug-disease 이질적 네트워크에 network clustering을 접목했다.
	> 여기서 drug-disease 모듈이란 drug repositioning을 위해 가능한 drug-disease pairs 를 추출하는데 사용될 수 있는 모듈을 말한다.
	> 이 네트워크에선 하나의 약이든 질병이든 유전자,타겟, 많은 특징들을 공유하는 두 Node는 연결되어있으며, 그 연결은 jaccard score로 weight를 얻는다.

4. Jin et al
	> 이분은 off-target effects(OTEs)의 효력을 이용하여, 암 치료 약을 리포지셔닝 하는 중요한 메소드를 개발하고 있음.
	> OTEs란 중요한 암 cell signaling pathways에 영향을 줄 수도 있는 방식임.
	> signaling proteins에서 drugs의 OTEs 은 
	> 
	> The OTEs of drugs on signaling proteins were recognized by a hybrid model composed by a network component and a regression model.
	> 
	> Bayesian Factor Regression Model 과 cancer-signaling briges라고 불리는 네트워크 component에 의해 구성된 하이브리드 모델에 의해 식별됨


#### Text mining and semantic inference
1. Intro
	> The biomedical and pharmaceutical knowledge available in literature
	> 많은 양의 drug와 disease에 대한 정보를 담고있는 DB와 문서의 분석으로 의학적 지식을 발견할 수 있음

	> 이 Method 에서 가장 중요한 것은 biological ontology를 만든다는 것이다.
	> biological ontology 란 다른 source 의 biological infomation 를 비교 분석할 수 있게 만드는 것이다.

	> In computer science and information science, an ontology is a formal naming and definition of the types, properties, and interrelationships of the entities that really or fundamentally exist for a particular domain of discourse.

2. Andronis et al
	> literature mining approaches와 sources for drug repurposing을 사용했는데,
	> 질병 A가 영양소 B의 부족으로 인해 발생 되는게 발견되고,
	> 또 다른 연구에서 약 C가 영양소 B의 개시자로 사용되는것이 발견되면,
	> 약 C는 질병 A를 위해 리포지셔닝 될 수 도 있다는 것을 발견했다.

3. Zhu et al
	> 의미론적 기술은 다양한 데이터 source의 통합과 새로운 약을 발견하는데,
	> 이 분같은 경우 FDA-approved breast cancer drugs 와 이 drug의 pathways, drugs, genes, SNPs and diseaes 관계들을 모델화 하는 ontology를 개발함
	> 새로운 drug-disease pairs는 ontology 기반의 정보화로부터 추측될 수 있다.
	
4. Chen et al
	> 이분 같은 경우는 통계 모델을 개발 했음.
	> 그 통계 모델은 의미론적 연결 네트워크로 부터 drug-target associations 에 접근 가능한 모델이다.
	> 그 의미론적 연결 네트워크는 drugs, chemical compounds, protein targets, dieases, side effects and pathways 와 그들의 관계로 구성되어 있음.
	> 그 예로
	> 이 모델은 국소 해부학과 drug와 target간의 부분 그래프의 의미를 고려하는데,
	> 이 다른 disease areas의 비슷한 drug-drug pair 는 잠재적인 repositioning opportunity를 나타낼 수 있다.
	> (통계모델을 이용하여, 국소 해부학과 drug와 target 부분 그래프의 의미를 탐색하는데,
	> 이를 통하여, 다른 disease areas와 비슷한 약-약 pair가 있을 경우 리포지셔닝 될 수 있음을 의미...)
	> 통계를 비교하여 drug-drug pair가 비슷한 결과를 나타내면 리포지셔닝 가능성 존재를 알려주는 듯

#### Validation for computational drug repositioning
######: 계산적 drug repositioning의 검증
1. Intro
	> Computational models 는 종종 소수의 흥미로운 결과를 예견한다
	> 그러나, drug repositioning의 궁극적인 목표는 환자에 이익을 주기 위해 몇몇 결과를 실질적인 치료 방법으로 발전시키는 것이다.
	> 그러므로 컴퓨터를 이용한 실험적인 검증단계는 중요할 수 밖에 없다.
	> 잘 알려진 한계에도 불구하고 in vitro and in vivo models 은 증가적으로 preclinical drug evaluation 을 위해 그 발견한 흥미로운 결과들을 검증하는데 사용되고 있다.
	
2. Zerbini et al
	> 이분은 몇몇 FDA-approved drugs가 clear cell renal cell carcinoma(ccRCC : clear cell 신장 세포암)에 민감하다는 것을 보여주었다.
	> drug의 효능을 확인하기 위해, 그들은 세포자멸사 assays과 이종이식 mouse models을 사용했으며, pentamidin을 ccRCC의 잠재적 치료 agent 임을 증명했다
	> 이것이 가능한 이유는 눈에띄게 종양의 세포자멸을 유도하고, 종양의 성장을 늦추기 때문임을 증명했다.

3. Kang et al
	> 이분은 cell 생존능력 assays 를 이용하여, computational search algorithm을 통해 발견된 the drug combinations를 검증했다고 함.
	> 그 이후, 암 세포를 죽이는데 큰 효능을 보이는 drug combinations 가 확인 되었다.

4. Vegner et al
	> 이분은 이전에 보고된 computational drug repositioning 전략에 대한 실험적 검증연구를 진행하였음.
	> 그 computational drug repositioning 은 ACE inhibition assay, COX inhibition assay, dopaminergic agonist and antagonist assay 를 통해 최고로 예상된 약의 효능을 확인하는 전략방법이였음.

5. Khatri el al
	>  in vitro and in vivo medels 에선, EHR이 the predictions을 validate하는데 도움을 준다고 한다.
	> 예를들어, 이분은 atorvastatin 을 장기 이식의 새로운 치료제임을 발견
	> 공공 마이크로 어레이 데이터 sets 의 meta-analysis 를 이용한 장기이식의 치료제
	> 또한 이분은 22년전부터의 2515명의 신장 이식 환자의 EMRs 분석을 통해 graft survival 상황에서 atorvastatin 이 긍정적인 영향을 주는 것을 검증했다.

	> graft survival : 이식 생존
	>atorvastatin
	1.an oral drug that is effective in lowering triglycerides (트리글리세리드)

6. Xu et al
	> 이분같은 경우 EHRs를 진성 type 2 diabetes 의 약인 metformin을 암으로 인한 사망과 연관지어 검증하는데 사용했다.

7. Notice
	> 적절한 검증 모델을 이해하고 선택하는 것은 the prediction의 성공에 있어서 중요하다.
	> 검증 모델의 문맥은 the prediction을 만드는데 사용된 것들로부터 달라질 수도 있고,
	> 몇몇 검증 모델 자체로도 신뢰할 수 없기 때문이다
	> 예로 

#### Current and future target areas: cancers, infectous and orphan diseases and personalized medicine
1. Intro
2. Li et al

#### Discussion
1. Intro
2. Challenges
	1. The transformation of theoretical omputational models into practical use is far from straightforward, due to some inevitable factors like missing data, data bias and technical limitations of computational methods.
	2. The lack of structured gold standard for drug repoisitioning made it hard to compare and evaluate the performance of computatinal methods.
	3. Although computational drug repoisitioning may merely shorten the process of drug discovery in preclinical and Phase Ⅰ  trials, challenges may still exist after Phase Ⅱ trials for the repositioned drugs

#### Conclusions


#### Keypoint
1. Various type of big data are publicly available for computational drug repoisitioning
2. Integrative repoisitioning strategies for heterogeneous data can help find new uses of old drugs.
3. Computational drug repoisitioning shows promises in accelerating drug discoveries for cancer and infectious and orphan diseases.


