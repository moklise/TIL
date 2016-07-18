#####Backgroud :

화학분자학과 화학 시스템 생물학은 풍부한 drug-target relationships를 이용한 network를 이용하여
값이 싼 in sillco prediction인 DR을 빠르게 사용하고있다.

통합된 화학적, 생물학적 네트워크는 
1. 안전하고 승인된 약에 새로운 indications을 가정화하고, 
2. 새로운 combination therapy design을 제안한다.
3. DTI network 는 또한 mode of drug action을 드러내어 의학적 부작용을 해석하는데도 사용할 수있음.

Semantic 표준과 기술은 여러 범위의 끊김없는 데이터 통합을 빠르게 진행시키고,
compounds, proteins, and genes 와 같이 다른 types의 다양한 biological entity로 구성된
이질적인 네트워크의 구성을 가능하게 한다.

몇몇 semantically linked datasets, PubChemRDF, Chem2Bio2Rdf, Bio2RDF, Open PHACTS, and ChEMBL RDF, 는
drug discovery에서 large-scare의 데이터마이닝을 촉진시킨다고 알려져왔다.


**SLAP**이라고 불리우는 통계적 모델은 Chem2Bio2RDF를 사용하여,
substructures, diseases, side effects, and pathways같은
다른 biological objects와의 간접적인 link나 path을 기반으로
compounds 와 proteins 사이의 직접적인 link를 예측한다.

**SLAP**이 새롭고 DTI를 예측하는 검증된 접근으로써 기존에 있던 대체들을 능가하는건 알려진 사실이다

그런데, DTI 를 예측하는 것은 복잡한 네트워크 분석에 있어서 기반적인 문제와 오랫동안 지속되어왔던 어려움인 link prediction과 같다.
In social networs,
관찰된 네트워크를 기반으로 측정된 topological proximity는 미래의 interaction을 제안하는데에 사용할 수 있음.
In drug-discovery 에서도
biological networks는 비슷하게 compounds와 protein targets들 사이의 잠재적인 association을 발견하는데 사용되어 질 수 있다.

전형적인 네트워크 기반의 DTI predictions은 
1. 직접 연결되거나 공통된 이웃으로부터 계산된 similarity profiles를 기반이며,
2. 이분네트워크에 한정되어 있음.

그러나, homogenous network를 위해 만들어진 대부분의 similarity 기반의 link prediction algorithms은
semantic network에서 정의된 heterogeneous types과 relations를 고려할 수 없다.

게다가, 연결에 있어서 무작위의 거대함을 증가시킬 수 있는 두 end nodes을 연결하는 long paths를 고려하는 일은 완전히 어려운 일이다.

이러해서, link prediction을 위해, meta-path topological features을 통합시켰다.
A meta-path는 합성된 관계이고, heterogeneous network에서 어떤 두 objects 간의 인접한 links의 sequence를 의미한다.
Adjacent links는 다른 semantics에 의해 정의되며, 
sequences에서 인접한 links의 다른 통합은 link prediction 에 눈에띄게 공헌할 것이다.

? Ajacent links는 다른 semantics에 의해 정의되며 ???

이는 meta-bath-based similarity가 heterogeneous information networks에서 information retrieval의 성능을 향상 시킬 수 있음을
보여준다.


<hr/>

A meta-path는 시작 object와 마지막 object를 연결하는 paths의 특정한 type이라고 정의된다.

한 특정 meta-path에 속해있는 paths의 총 수는 '**path count**' 라고 불리우는
시작 object와 마지막 obeject간의 the strength of associations을 평가하는
중요한 topological feature 이다.

예를들어, a compound와 a protein target이 다른 타임들의 mutiple paths를 통해 연결되어있을 수 있다.

(A) compound --similar to--> compound --binds to--> protein;
(B) compound --binds to--> protein --binds to--> coumpound --bidns to--> protein;
(c) compound --has part--> substructure --part of--> compond --binds to--> protien --similar to--> protein;

이 세가지 meta-paths 는 the atrting compound 와 the ending protein을 연결하고 있다.
(A)는 다른 비슷한 compound가 결합할 수 있는 protein에 결합할 가능성이 큰 compound를 보여주고있다.
(B)는 하나의 관찰된 protein을 공유하는 two compounds가 또 다른 protein도 공유할 수 있다는 것을 보여준다.
(C)는 공통의 substructure을 공유한 two compounds들이 비슷한 protein sequences를 가지고 있는 two dirfferent protein targets과 결합할 수 있다는 것을 보여준다.

SLAP은 link prediction에서 the importance of each meta-path 를 평가하는 통계적 모델을 사용한다.
the importance of each meta-path 란 임의적으로 뽑아진 drug-target pairs의 a set 에서의
connectivity property의 분산을 기반으로 각각 평가되어 지는 것이다.

? importance of each meta-path

몇몇 Meta-paths들은 통계적 중요성들에 따라 선택되어지며,
선택된 meta-paths의 모인 connectivity properties 는 DTI를 예측하기 위해 사용된다.



<hr/>

The present work은 SLAP에 대안적인 DTI 접근방법을 제공한다. // Meta-based 말함
meta-path topological features의 중요성을 연구하기 위해 통계적 모델을 사용하는 것보단,
우리는 machine learning algorithms, including Random Forest (RF)와 SVM 을 사용할 수 있고,
DTI을 예측하기 위해 Binary classification models를 구성할 수 있는 Framework를 제안한다.
the predicted links를 통해 A more complete drug-target connectivity map을 만들 수있다.
> DTIs 를 예측하는건 Binary Classification Models 이구나


machine learning models를 사용하면,
(the contributions of different meta-paths to the link prediction과 같은)
classification models이 만들어지기 때문에
featrue imporatance 를 동시에 계산되어질 수 있다.

추가적으로, SLAP은 단지 topological feature의 path counts를 고려하지만,
우리가 제안하는 이 접근법은 path count,including the toplogical featrue space를 더 많아지게 하기 위한, random walk, 표준화된 path count 그리고 대칭적인 random walk 에 표준화 과정들의 다른 종류들을 적용 시킬 수 있다.


SLAP과 우리의 접근법을 비교하기 위해,
drug candidate와 biological annotaions을 집중하는 Chem2Bio2Rdf 라고 불리는 semantic network로 link prediction experiments를 수행했다.
비록 이 제안된 접근은 현재 연구에서는 더 complete한 drug-target connectivity map를 구성했지만,
이것은 link prediction을 위한 이질 네트워크의 the toplogical features를 연구하기 위한 machine learning algorithms을 사용할 수 있는 framework로써 일반화가 될 수 있다.
compounds간의 구조적인 similiarity links와 proteins간의 sequnce similarity links 는 the semantic network를 확장시키기 위해 추가되어 질 수 있다.
PubChem resouces로부터의 links와 이웃하는 similarity의 유용함은 semaintic link prediction의 상황에서 조사되어진다.

<hr/>

#####Semantic netwrok
: semantic netwrok에 대한 소개 

In the Chem2Bio2RDF semantic network 에서는,
9가지 뚜렷한 semantic types이 존재한다.
Compounds
proteins
adverse side effects
Gene Ontology (GO) annotaions
ChEBI types
sbstructures
tissues
biological pathways
diseases

10가지 다른 semantic links 들은 통합되었다.
links
from compounds to ChEBI types
from compounds to proteins
from compounds to substructrues
from adverse side effects to compounds
from diseases to compounds
from proteins to proteins (PPI)
from proteins to Go annotations
from diseaes to preoteins
from path-ways to preteins
from tissues to proteins

또, link prediction의 성능을 높이기 위해, 우리는 linked data set에 2 more semantic links를 추가했다.
compound neighboring links based on 2D structural similarity
protein neighboring links based on sequence similarity
이 The similarity neighboring links 는 PubChem databases로부터 얻어왔다.

위의 총 22 adjacency matrixes는 두 객체간의 the semantic links를 기반으로 계산되어진다.
이 The adjacency matrixes의 요소들은 2 value를 가지고 있다.
0 : link가 관찰되지않음.
1 : link가 관찰됨

이 adjacency matrixes의 semantics와 statistics는 Table 1에 열거되어있다.
이들은 the meta-path-based topological features를 계산하는데 사용된다.
Chem2Bio2RDF dataset에서의 모든 the semantic links들이 거꾸로도 가능하다는 것은 (resersible) 눈에 여겨볼만 하며,
그 the revese semantic link 를 위한 the adjacency matrix는 the original adjacency matrix의 전치행렬을 통해
얻을 수 있다.

<hr/>
#####Meta-path-based topological features
The meta-path topological features는 several adjacency matrixes를 multiply함으로써 계산된 commuting matries로 encoded 되어있다.
compound와 protein간의 the links를 예측하기 위해,
우리는 철저하게 가능한 총 51개의 meta-paths을 열거했다.
각 commuting matrix는 The given length의 meta-path 의 특정한 타입을 보여준다.
// The lenght에 따라 이 commuting matrix가 어떤의미를 가지는지를 보여준다는거 같음.

The lenght of the meta-paths는 곱해진 adjacency matrixes의 수와 같다.
51 commuting matrixes 중에서
4 meta-paths 의 길이는 2
11 meta-paths 의 길이는 3
36 meta-paths 의 길이는 4
그리고 길이가 4보다 더 큰 meta-paths들은 link prediction에 중요한 공헌을 할 수 없을것이라고 판단하였다.
이 the commuting matrix에서의 요소들은 compounds와 proteins을 연결하는 path instances의 숫자를 의미한다.
그리고 음수를 가지지않는다.
The semantics and statics of commuting matrixes는 Table 2에 열거되어져있다.

예를들어, the commuting matrix C15는 하나의 meta-path를 보여준다

compound --similarity to-> compound --bind to-> protein --similar to->protein
위의 mata-path는 A2, A11, A12의 adjacency matrixes를 곱함으로써 계산했다.
위 계산은 Armadillo C++ linear algebra library를 사용했으며, 모든 adjacency and commuting matrixes는 메모리 소비를 줄이기 위해
sparse matrix로 encoded 한채로 수행하였다.

// 즉 정리하면, meta-path, 두 obejct 간의 관계를 이용한 path 를 기반으로 두개의 metrics를 만들었음.
<hr/>

Topological feature의 Two measures가 사용되었다.
Path Count(PCij) : commuting matrix에서의 요소의 값을 나타내는 nodes i and j 간의 path instances의 수를 나타냄.
Random Walk(RW) : path instances의 number에 대한 표준화 과정으로써 the network의 전체적인  connectivity 에 기반한다.
RW 는 

<hr>
#####Machine learning dataset
Supervised learning models을 만들기 위해, Positive and Nagative label이 필요하다.
그래서 우리는 compounds and protein 사이의 관찰된 link 를 Positive로 보았다.
Drugbank로부터 총 5387개의 positively한 labeled links를 얻어냈고,
이는 SLAP algorithm의 예측 성능을 테스트 하기 위해 사용될 것이다.

Dataset에서 관찰되지않은 links는 가짜 link거나 potential future link임을 의미한다고 볼 수 있다.

negative labels에 대한 실험적 증거를 찾기위해,
우리는 PubChem BioAssay database를 조사했다.
만약 the experimental bioactivity value가 10μM (micro meter)보다 크다면,
그 compound protein pair의 link는 negative label 이 된다.

? bioactivity value 가 뭐지
? negative label의 실험적 증거를 찾기위해 조사를 했는데, 조사를 통해 negative lable을 찾아냈대
? ?

따라서,
우리는 Chem2Bio2RDF semantic network에서  coumpounds and proteins 간의 5.6 billion unobserved links 중
26682 nagative labels을 발견했다.

// 이제 얻은 label 처리 함
예측 성능을 선행지식없이 평가하기 위해,
the meta-path-based topological features가 계산되면,
Chem2Bio2RDF에서 가져온 the positively labeled links 는 제거된다. // 왜냐하면 positively한건 이미 찾아진거거든.
The positively and nagatively labeled links 는 통합되고,
training set과 test set으로 임의적으로 2 : 1 비율로 나누어진다. // 

The Traning set에는
3591 positively labeled links와
17788 negatively labeled links가 존재한다.

The Test set에는
1796 positively labeled links와
8894 negatively labeled links가 존재한다.

<hr/>
// 더 테스트 한다는 얘기

The network는 시간이 지남에 따라 새 links를 찾음으로써 진전한다.
network connectivity의 진전을 발견하는(새 links를 찾는) 제안된 framework의 능력을 더 테스트하기 위해,
the PubChem BioAssay database으로부터 더많은 a set of DTIs를 가져왔다.
PubChem Bio-Assay는 데이터 제공자가 작성한 compounds and protein 간 bioactivies를
assay descriptions과 activiy values에 따라
active, inactive, unspecified groups 로 분류한다.

Active :
PubChem BioAssay에서 compounds 와 protein targets간의 interaction 이
1. Active 로 분류되고
2. Active interaction pairs의 Activity values가 1μM 보다 작으면
the link는 positive label 로 분류된다.

Inactive :
PubChem BioAssay에서 compounds 와 protein targets간의 interaction 이
1. Inactive 로 분류되고
2. the interactions 간의 activities가 존재하면,
the link는 nagative label 로 분류된다.

현재의 Chem2Bio2RDF semantic network에서 얻어진
A set of 145622 positively labeled links + 600000 negatively labeled links 는 a training set을 구성했으며,
Chem2Bio2RDF semantic network이 아닌,
bioassay experiments를 통해 식별된 TP DTIs에서 가져온
다른 A set of 43159 positively labeled links + 195000 negatively labeled links 는 a test set을 구성했다.

(위에있는) test set에서의 the positive DTIs은 network 구성 이후에 얻어지기 때문에,
이 독립적인 test set은 현재 network의 the topological features에 기반한 the future network에서 the links들을 예견하는 능력을 검사하는데 사용된다.
// 그니까 이 네트워크에선 안쓰이고 미래의 네트워크에서 사용된다는 거네

<hr/>
#####Binary classification models
PubChem databaes에서부터 가져온 the similarity neighboring link 가 어떻게 link 예측 성능을 높일수 있을지를 보이기 위하여,
우리는 two sets of path count topological featrues 기반의 또 다른 machine learning models을 구축했다.

Feature set Ⅰ 은 similarity neighboring links를 포함하는 어떠한 meta-paths도 포함하지않고,
단지 29 path count topological featrues를 가지고 있다.
Featrue set Ⅱ 는 모든 51 commuting matrixes의 encoded 된 path counts를 포함하고 있다.
우리는 또한 풍부한 topological feature space를 이용하여, 예측 성능의 향상을 테스트 하였다.

RW normalization은 51 path count topological features 에 적용되었으며,
>  51 commuting matrixes가 path count topological features 을 의미하는 거였나봄

PC와 RW를 통합함으로써,
102 topological features를 담고있는 feature set Ⅲ 를 만들었다.

<hr/>

Two popular machine learning algorithms을 조사했음.
Random Forest (RF)
: a collection of decision trees from bootstrap samples of the traning data without pruning,
: RF는 the ensemble trees의 주요한 투표를 기반으로 예측한다.
RF는 일반화된 test error의 치우치지않은 estimate때문에 Out-of-Bag(OOB) error에 이점이 존재한다.
그래서, cross-validation이 필요없다.
RF는 the importance of features를 잘 계산할 수 있다.
주어진 Feature의 Values는 모든 compound-protein pairs에 걸쳐서 변경된다.

Classification accuracies 나 node impurities (Gini indexes)은 변경 전과 후에 측정된다.
>	impurity : 불순물
그리고 그 측정의 차이는 feature importance의 평가에 사용된다.
현재 연구에선 the number of trees 에 대한 
A default value는 (ntree = 500)으로 사용된다.
이 (ntree = 500)은 많은 케이스에서 만족되는 수치다.

parameter mtry를 튜닝하기 위한
The optimal value 는 grid search에 의해 발견되어진다.

<hr/>

Tree moedls과 대조적으로
SVM (Support Vector Machine)은 
the structural risk minimization principle 과 Vapnik-Chervonenkis (VC) dimension 에서 기인한
statistical learning을 기반으로 한다.
이 연구에서는
A soft margin SVM with radial basis function (RBF) kernel in the Gaussian form
을 사용한다.
>? A soft margin SVM

Tuning parameters (C and λ)을 위해
The optimal vlaue 는 grid search에 의해 10-fold cross-validation 함으로써
제거된다.

<hr/>

The classification performances 는 the F1-score을 사용함으로써 평가된다.
이 The F1-score는 precision 과 recall의 the harmonic mean 
>조화 평균(調和平均)은 주어진 수들의 역수의 산술 평균의 역수를 말한다. 평균적인 변화율을 구할 때에 주로 사용된다.


F1 score : 2TP / 2TP + FP + FN


F1-score는 통계적 가설 Test에, 특히 불균형한 dataset에, 사용할 수 있다.
RF 와 SVM은 모두 the probabilities of classifications를 계산할 수 있고,
그 the probabilities를 이용하여 rankings를 만들어낼 수 있다.
Ranking에서의 예측 성능은 ROC ( Receiver Operating Characteristic ) 과 PR (Precision Recall) curves로 모든 models에서 평가된다.
> 그러니까 만들어낸 랭킹을 어떻게 어떻게 하면 예측성능을 평가할 수 있다는거네

AUCROC와 AUCPR (The area under te curve for _)을
R package 'Miscellaneous Esoteric Statistical Scripts' (MESS)을 통해
the natural spline interpolation을 사용하여 계산할 수 있다.

Virtual screening experiments 에서 가장 중요하다고 생각되어지는
The early hit recognitions 는 
BEDROC (Boltzmann-enhanced discrimination of ROC) 에 의해서 평가되어진다.
BEDROC 는 R package 'enrichvs'로 사용하여 계산할 수 있다.