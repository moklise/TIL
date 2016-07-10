#Literature mining, ontologies and information visualization for drug repurposing

<hr/>
####pubMed
####Literature mining

Swanson's ABC Model

스완슨은 2가지 Type의 ABC 모델을 주장했음.
Closed Process 와 Open Process

Closed Process 는 Starting concepts A and C
Open Process 는 Starting concept A
그 예로는 The effects of which are mediated by this mechanism.

The discovery of novel links between seemingly unrelated concpets.
IE
NER 




Information Extration

The NER step is a prerequisite for any IE project.

Name Entity Recognition
 : free text 로부터 biomedicalterm의 식별이 이루어진다

However, it is a quite difficult task due to the lack of standardization of names and the issues of synonymy and polysemy

ex)
MAPK14 - mostly use
p38 MAP kinase
mitogen-activated protein kinase 14



하지만 여기에는 식별에 문제가 있음.


요즘엔 Machine Learning을 이용하여 모호한 데이터를 식별함.

co-occurence : 같은 문장 내에서 발생하는 모든 단어를 연관이 있다고 생각하는 것.

하지만 이 방법은, the high rate of false-positive를 만들어냄

그래서 NLP의 개발이 활발해지고있음.

NLP
1. Tokenized word
2. Expending to sentence
3. 나온 Entity를 a biomedical category로 Mapping  하거나
모든 문장과 구절을 트리로 구성함.

결론.
Co-occurence보다 NLP가 new discovery에 대한 더나은 guidance를 제공함.


####Ontology Moddeling
Biology같은 경우는 다른 과학분야와 달리
수치적으로 완전히 계산되어있는 분야가 아니기때문에
수학공식과 다르게 기록될때 주관적인 방법으로 서술되어있는 경우가 있음.
그러기 때문에, 다양한 formats으로 기록되어진 지식들의 다양한 범위의 사실들을 통합하는 표준화의 수단으로 사용되고있는 Ontology는 필요해질수밖에없다.
그래서인지,
Despite some shortcomings of popular semantic web languages to comprehensively define the often incomplete nature of biomedical data, 이 semantic web language는 biomedical 분야에서 관계를 보여주는데 널리 사용되어졌다.

Semanticf web technologies는 concept의 description을 위한 수단으로써 널리 사용되어왔다.

그중에는 RDF 기반의 OWL ( Ontology Web Language ) 가 존재한다.


#### Visualization thecnique
시각화는 Ontological 접근 중에서 가장 흔한 사례이다.
대부분 semantic tools은 시각화 기능을 포함하고 있다.
Graphical 표현은 인간 뇌에 더욱 효과적인 공간을 제공하며, 즉각적인 시각판단이 가능하다는 이점이 있다.

시각화에는 3가지 타입이 있다.
네트워크 그래프, 히트맵 그리고 tools enabling the visualization of docking experiments

Graphics 언어도 존재하고, 툴도 존재하기때문에, 최소한의 노력으로 복잡한 데이터를 시각화 할 수 있다.

하지만 한계점도 존재한다.
많은 양의 데이터를 시각화 하려고 할때 2D의 시각화시 더 복잡해 질 수 있다.
그때는 3D 시각화가 적절한 방법이다.

####Traversal to the area of DR

#### Concoluding Remark
DR는
한 사람이 질병에 관한 분자나 약의 메커니즘을 잘 알고있으면 있을수록,
더 정확한 증상을 근거있게 예측할 수 있거나 부작용으로 이끄는 signaling pathway를 피할 수 있을 것이다.

약이나 잘 알려진 질병들의 대한 정보들의 몇몇은 bioinformatic 으로나 db에 잘 정리되어 저장되어있지만,
대부분들의 의학적 정보는 free format으로 저장되어있다.
그렇기떄문에,LBD를 동반한 IE가 특히 이미 존재하는 약을 새로운 약으로 이끌어내는 가설을 발생시키는데 좋은 전략이라 할 수 있다.
게다가 Information Visualization techique은 이 과정에서 좋은 Guidance가 되어줄 것이다.

그리고 DR 과정에서 중요한 점은
1. 모든 가설은 전문가에 의해 직접 만들어져야 한다.
직접 함으로써, uncertainties가 remove되고, novel association과 연관된 다른 parameters들을 고려 할 수 있다.
2. novel use of a drug와 함께 연관된 부작용의 측면이다.

DR은 기존의 약의 사용이 전제이지만, 약이 부작용을 일으킬 가능성이 없다고 예상해서는 안된다.