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

##### For Instance
<hr/>
---------- The open discovery mode of ABD Model 을 사용한경우
??? 확인이 필요함


Both open and cloes LBD Mode는 literature mining 연구자들에게  discovery procees를 자동화시키는 툴을 만들도록 영감을 주었다.
그 툴은 IE techniques이 과학적 문서로 부터 관련된 정보를 효과적으로 추출할 수 있는 주고,
최신 과학문서로부터의 discovery 과정에 추가적인 데이터 형과 sources를 통합시킨다. ( ??? )

최신 과학문서에 묘사된 LBD에서의 거의 모든 적용들은 잘 알려진 drugs와 영양보충제를 사용하면서, diseases를 위한 treatments 발견을 시도한다.
적용가능성과 DR과 LBD의 관련성을 말해주면서 말이다.

그리고 concepts사이에서의 관계들이 거의 같은 abstract에서 facts와 terms의 co-occurrence를 기반으로 독점적으로 based되어있는것은 흥미로운 사실이다.

###### Smalheiser and Swanson
the A and C concepts 사이에서의 간접적인 연결의 해석에 자동화 단계를 추가하고, original ABC모델의 closed discovery mode를 만드는 Arrowsmith라는 web tool의 결과물과 함께 진행했다.

###### Gordon and Lindsay
the open discovery mode를 사용하고, Swanson의 발견을 재생성하기 위해 title과 abstracts의 어휘적 통계를 사용했다.

###### Weeber
Gordon and Lindsay와 같은목적으로 UMLS와 자연어를 UMLS concepts으로 변환하는 어휘적 툴을 사용했다. 이들이 만든 이 툴은 DAD 이라고 불리우며 MetaMap Program을 기반으로 하고 있다.

그리고, ABC model의 정교함을 따라서 탈리도마이드를 위한 네가지 치료법을 만들어냈다. ( myasthenia gravis, chronic hepatitis C, Helicobacter phlori-induced gastritis and acute pancreatitis )


###### LitLinker and Telemakus
시스템 이름인가봄?
LitLinker 와 Telemakus 는 MetaMap과 UMLS의 이점을 취하는 두가지 시스템이다.
LintLinker는 또한 용어 선택과 단계의 감축을 위해 MeSH를 사용했으며
Telemakus는 또한 직접 제작한 네트워크의 시각화를 제공한다.

###### Van der Eijk et al
abstracts로부터 IE를 진행하고, 모든 concepts를 n 차원공간에 두기 위하여 ACS ( Associative Concepts Sapce  ) Algorithm을 기반으로 하는 co-occurence를 진행하였다.

가까운 거리에서의 Concepts은 연관이 있다고 고려되어지고,
만약 concepts끼리의 직접적인 연결이 없으면 잠재적인 새 연관이 발견 되어진다. (????????)

###### Wren et al

MEDLINE에서 추출한 biomedical concepts의 네트워크를 기반으로 co-occurence를 구성했으며,
cardiac hypertrophy and Chlorpromazine 사이의 새로운 관계를 추론하기 위해 연관이 얼마나 되어있나 ( The strength of association )를 이용했다.
그 다음, 저자들은 went ahead 하고, animal models에서 이 관계를 validate 하였다.

###### Narayanasamy et al
Biomedical concepts을 이용해 MEDLINE을 이용하여, an association Graph를 제작하였다.
그다음, 이 Graph ( Network ) 를 TransMiner라는 툴에서  transitive association를 찾는데 사용되었다.


<hr/>
--------- LBD의 closed discovery mode를 사용하는 연구 -------


###### Ahlers et al
MEDLINE에서부터 의미론적 예측을 추출했으며,
이를 정보를 암과 anti-pychotic agents 사이에서의 link를 제공하는 잠재적인 단백질을 찾아내기 위해 사용했다.

###### Petric et al
autism과 calcineurin을 연결하며, Discovery Process에서 드물게 나타나는 용어를 강조하였다.


###### Hristovski et al
MEDLINE에서부터 추출한 Concepts 사이에서의 association rules을 계산하는 BITOLA 라는 툴을 개발했다.
이 rules는 concepts 사이의 알려진 관계를 나타내는데 사용된다.
결과물은 association strength를 측정하는 parameters에 따라 ranked 된다. 

###### Baker et al
The closed discovery mode의 발견 잠재성을 말해주는 다른 연구에서 
Bakse는 MeSH terms를 MEDLINE abstracts에서 drugs와 drus Effects를 찾아내기 위해 사용했으며,
중간의 B concepts으로써의 proteins을 사용하여,drugs들을 diseases에 연결시켰다.

###### Ha et al
이미 존재하는 약과 drug target 사이에서의 새 관계를 예견하기 위해
chminformatics와 text mining techniques를 사용하는 프로그램을 만들었다.

###### Zhu et al
compounds를 특징화 하고 compounds와 genes, diseases, and biomedical articles 사이에서의 명확하지않은 관계를 찾아내기 위해 모든 web services를 사용하는 data mining tool을 마들었다.


##### Srinivasan and Libus
MeSH terms 를 사용했으며, B concepts를 선택하기 위해 최종적으로 turmeric/curcumin의 치료 잠재성을 탐색하기 위한 C concepts의 ranked list를 만들어 내는 weighting system을 사용하는 알고리즘을 개발했다.


###### Conclusion




####Information Extration

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

##### For Instance

######


####Ontology Modeling
Biology같은 경우는 다른 과학분야와 달리
수치적으로 완전히 계산되어있는 분야가 아니기때문에
수학공식과 다르게 기록될때 주관적인 방법으로 서술되어있는 경우가 있음.
그러기 때문에, 다양한 formats으로 기록되어진 지식들의 다양한 범위의 사실들을 통합하는 표준화의 수단으로 사용되고있는 Ontology는 필요해질수밖에없다.
그래서인지,
Despite some shortcomings of popular semantic web languages to comprehensively define the often incomplete nature of biomedical data, 이 semantic web language는 biomedical 분야에서 관계를 보여주는데 널리 사용되어졌다.

Semanticf web technologies는 concept의 description을 위한 수단으로써 널리 사용되어왔다.

그중에는 RDF 기반의 OWL ( Ontology Web Language ) 가 존재한다.

##### For Instance

###### Ashburn et al


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
####Drug Repurposing Applications

###### Frijters et al.
drugs, genes and diseases 사이의 새 연결을 발견하는 목적의 literature mining tool CoPub Discovery 을 만들었다.
CoPub Discovery 은 Swanson's ABC 모델을 기반으로 만들어졌으며,
Gene 이름과 다른 biomedical concepts는 MEDLINE astracts 에서부터 추출되고, co-occurence를 이용하여 서로 association 된다.

저자들은 co-citations의 강도를 보기 위하여 상호적인 정보기반의 척도를 이용했다.
그리고, disease-gene, drugs-disase, drug-biological process and biological process-drug relationships 와 함께 연구들을 보여주었다.

그 시나리오는 dephostatin, tyrosine phosphatase inhibitor and damnacanthal, tyrosine kinase inhibitor, being relevant to cell proliferation 의 식별을 이끌어냈다.
In vitro cell proliferation 실험은 low micro molar concentration 상황의 cell proliferation 의 과정에서 이 두 compounds 의 영향을 검증하였다.


###### Li et al.
disease-특정drug-protein 연결 maps을 만드는데 사용할 수 있는 Computational Framework을 고안하기 위해 literature mining 과 함께 단백질 상호작용 데이터를 통합시켰다.
저자들은 알츠하이머를 위해 사례연구를 하였다.
그들은 OMIM으로부터 약하게 되어지는 질병관련 단백질의 리스트와 함께 시작했다.
OMIM이란 직접 disease gene lists를 포함하는 것이며,
OPHID으로부터 상호작용하는 단백질과 함께 수정한다.
(??????)

AD-관련 단백질 리스트를 사용하여,
PubMED으로부터의 abstracts의 세트를 가져왔다.
그리고 이를 AD와 연관된 새 drugs 를 식발하기 위한 목적으로 이 articles들로부터 잘 알려진 모든 drugs들을 추출한다.
이 접근을 통해, 그들은 dilitiazem antihypertensive agent and quindine, an antiarrhythmia agent 를 AD의 후보자로서 을 선택했다.

정보획득과 IE with ontology와 같은 텍스트 마이닝 tasks 사이에서의 암시적인 관계는 지금까지 묘사되어졌다.
이 예제들은 통제된 사전과 온톨로지에 의해 가져와진 지식들을 주장하는 목적과 함께 추출된 정보들을 저장하는 수단으로써의 사용을 보여주고있다.
(??????)

마지막으로 그들은 온톨로지로부터의 더 높은 순서 추론을 위한 의미론적 기술들의 적용을 위한 단서를 제공했다.


drug disease relation 식별에 성공적으로 적용되어지는 semantic queries의 사용의 예제는 바로 Qu이다
###### Qu et al.
DDCO ( the disaes drug correlation ontology ) 라고 불리우는 ontologies의 semantic web은 DrugBank, Entrez Gene, Go, OMIM, KEGG, BioCarta, Reactome, UMLS and GEO에서 가져온 온톨로지를 통합함으로써 만들었다.
이 관계 네트워크는 te semantic web 과 SPARQL ( the query language for ontologies, disease Systemic Lupus Erythematosus 약을 찾음으로써 확인하고, drug-disease associations 를 추론할때 사용되어짐)에 가져와진 혼합체를 사용하여 만들어졌다.

###### Cockell et al.
새로운 drug-disease 관계를 추론하기 위한 접근을 기반으로 하는 graph를 보여줌.
drugs, protein, diesases 사이의 560,000의 relationships을 가지고있는 120,000 concepts의 그래프는 DrugBank UniProt, HRPD, KEGG, Pfam, SynAtlas, G-sesame, OpenBabel, and BLAST로부터 데이터를 가져옴으로써 만들어졌다.
이 Ondex platform은 이들의 다양한 소스로부터의 데이터가 하나의 큰 데이터 set과 visualization 과 비교되기 위하여 사용된다. ( 하나의 큰 데이터와 여러 소스에서 가져온 데이터를 사용할라고 비교)

그다음 DR 가능성의 추론은 interconnection 그래프와 semantic web query techniques을 이용하여 수행된다

###### Choi et al.
Protege tool을 사용하여 drugbank, pubchem, uniprot에서부터 가져온 데이터들을 통합한 SMO ( Small Molecule Ontology ) 를 구성하는 방법론을 묘사함.

The ontology는 RDF triples을 사용하는 OWL_DL이 개발되어지는데 사용되었다.

The finished ontology는 DR을 위한 새로운 연관을 추론하는 Semantic web technogoies의 적용가능성을 보여주기 위해 SPARQL를 이용하여 queried 되었다.

The ontology schema와 수행되어진 작업을 위해 생성된 the specific instance는 공공적으로 사용할 수 있다.

###### Cure and Giroud et al.
Drug databases에 저장된 data의 질을 향상시키는 workflow를 보여주었다.

1. 이미 존재하는 기술들을 semantic web compatible format에 통합한다. 이 과정은 규정 안내와 결과 ontology의 연관들과 concepts들의 정제에 의해 따라온다. (?)

새로운 concepts은 유도적인 추론을 drug database에 적용시킴으로써 ontologies와 함께 연관되어진다.

그다음 The ontologies 는 데이터베이스 내에서의 데이터품질저하를 찾고 고치는데 사용된다.
그다음 품질저하에 대한 이 확인들은 데이터 무결성을 유지하며, DB를 사용할 때마다 수행되어진다.

-------- Visualization Techniques Example --------
DR과 관련있는 The visualization techniques는 
dectection을 직접 수행하는 exploration 툴로써의 간단한 행동이나
흥미있는 연관을 추구하는 자동알고리즘을 컨셉화 하는데 사용된다.

###### Cerami et al
novel gene-disaes associations의 발견을 위한 그래프 이론적 분석의 적용 : Cerami

저자들은 the Newman-Girvan module detection algorithm을 후보자인 driver를 찾기위해 사용했다. 
ex) genes responsible for Glioblastoma, such as the AGAP2 gene and three signaling modules including one involved in microtubule organization

###### Keiser et al
새로운 타겟들과 결합하는 the ligands 들의 similaity 를 비교함으로써 이미 존재하는 새로운 타겟들을 예견하는 능력을 보여주었다.

###### Campillos et al
위와 비슷하게, 관련없는 drugs의 side effects similarity를 이용함으로써 이미 존재하는 drugs 에 대한 새로운 targets을 예견했다.

위와 비교해서
###### Hu and Agarwal 는 multiple interaction networks를 통합시킴으로써 더많은 노력이 수행되었다.

###### Pujol et al
diseases는 복합적이고 ,high target specificity drugs, 현재 말 할 수 있는 것보다 더 많은  multiple pathways에 포함되어있다고 주장했다.
이것이 사실임을 보여주기 위하여,
그들은 node centrality, modularity, between-ness, shortest path, clustering and more to decipher the complex biological networks 같은 네트워크 통계와 위상수학 기술들을 사용할 것을 제안했다.

###### Paolini et al
모든 포괄적인 global DB를 만들기 위한 시도에서, 그리고 이런 문맥에서,
하나의 시스템에서 몇몇 source로 부터 SAR (structure-activity relationships)로 통합했다.
drug targets의 다양한 classes 사이에서 연관을 시각화 하기위해,
모든 잘 알려진 drug target families 사이의 혼합성을 비교하기 위한 Heat Map을 사용하며, 그들은 네트워크를 그것들과 결합되는 drugs에 따라 the targets의 연결성을 보여주기 위하여 사용한다.

위의 방법은 drugs 나 포함되어있고 이미 DB에 저장된 the targets의 선행지식이 필요하다.


###### Iorio et al.
선행지식이 필요없는 많은 실험에 의해 발생된 전사적인 datagene signatures 을 기반으로 한 비슷한 접근을 제안했다.
그들이 만든 the drug-drug network는 the drug profile similarity의 척도인 the drug distance를 기반으로 만들어졌다.

###### Narayanasamy et al
a network를 만들고, 전사적인 connections을 찾기 위해
Literature mining data들은 TrasMiner를 이용하여 진행했다.

###### Li et al
Heat Map을 protein-compound association profiles의 similarity를 비교하기 위하여 사용했다.
hierarchical clustering을 통한 통합에서.

###### Korbel et al

heatMap 을 이용한 더 모호한 접근은 Korbel 의 경우에서 발생한다
literatrue과 comparative genome analysis를 통해 genomic data와 표현형을 연결시키기 위해 사용했다.


###### Campbel et al
conception에서 production으로의 target drug를 찾고 시각화 하기 위한 더 큰 시도는 Campbell에 의해서 수행되었다.
이는 또한, 약 개발의 최초 단계에서 heatmaps을 사용하였다.

###### Clinical Outcome Search Space


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