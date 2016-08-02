
####Introduction to graph representations and graph algorithms for biomedical relation extraction
> 그래프는 어떻게 구성되어있고 어떤 알고리즘의 종류로 이용되는가.


Narrative sentences 을 위한 Graph representation은 
자연적으로 nodes and edges로 표현되는 the choice of information 으로 구성된다.

Common node choices 는
tokens
named entities
senmantically labeled named entity
and relations themselves within nested relations.
를 포함한다.

Those choices are 
in the order of encoding increasingly enriched and complex semantic information.

> node들은 증가적으로 풍부하고 복잡한 의미론적 정보를 담고있는 순서다.

Common edge choices 는
syntactic dependency,
syntactic constituency link,
event argument,
association
같은것을 edge로 본다.

These choices는 
semantic and syntactic information을 the graph representation 에 통합시킨다.
to different degrees.

> 그니까 위에꺼는 보통 graph representations을 진행할때
> 주로 Node 로 지정하는 것
> 주로 Edge 로 지정하는 것을 보여준다.

Graph mining algorithms은 직접적으로 relations를 추출하기 위해 적용될 수 있고,
useful featrues를 구성하기 위해 적용될 수 있다.

빈번하게 사용되는 알고리즘은 다음에 따라 분류 할 수 있다.

- Some identify shortest path (or its variant) between concept pair ( 다익스트라 같은 기본적인 알고리즘을 사용해서 수행될 수 있는 알고리즘)
- Some create association graphs then try to apply customized labels to them.
- Some use subgraph matching to compare the similarity between subgraphs based on a score that aggregates node distances and edge distances
- Some carry out frequent subgraph or subtree pattern mining to directly extract candidate relations
- Some directrly parse graph representation of relations from sentences by intergrating the graph structure into the learning objective of the parsers.

다음 섹션에서 state-of-the-art methods를 review할때,

우리는
그래프로 표현된 정보
graph 알고리즘 
의도된 사용
을 중심으로 위 사항들을 Table 1에 요약해놓은 것 처럼

각 Method를 특징화 했다.

<hr/>

####State-of-the-art methods for biomedical relation extraction

Biomedical relation extraction을 위한 방법론은 높은 관심을 받아왔다.
Conventional approaches는 co-occurrence statistics를 관련성을 위해 사용 한 것에 초점을 두고있다.
> 과거의 방법들은 co-occurrence statistics로 relation로 찼아왔어

몇몇 Clinical NLP systems는 직접만든 syntactic and semantic rules를 미리 서술된 semantic relations를 추출하는데 사용했다.
such as MedLEE and SemRep

그러나 이 clinical NLP systems는 새로운 subdomains에 적용시키기가 어렵다.

> 서브도메인 다른 분야에서 사용하기가 어렵다 뭐 이런거같은데
> 응용하기가 어렵다?

최근 연구는 
'relation을 추출하기 위해 자연어의 constituency and dependency structures를 충분히 탐색하고 일반화 할 수 있는 메소드를 개발하기 위해'
syntactic parsing에 더욱 더 초점을 두고 있다.

> 여러 'subdomain,분야' 에서 사용할 수 있고 성능이 보장된 메소드를 만들고자 하였나보넹

In this section, we review the state-of-the-art approaches where graph (including tree) mining techniques are used to derive relations from syntactic or semantic parses.

In this section, 우리는 tree를 포함한 graph mining techniques에 대해서 review 할 것이다.
이 graph mining techniques은 syntactic or semantic parses으로부터 relations를 얻어오는데 사용되어 온것이다.

우리는 메소드들을 카테고리화 했다.
그것들의 문서가 주로 scientific publications or clinical narratives와 연관이 있는지 없는지에 따라. 
왜냐하면 그 content difference가 the methods와 resources used to extract relations 에 영향을 종종 미치기 때문에.

> 문서는 위에 parses를 가르키는 거 같고
> scientific publications 나 clinical narratives와 연관이 있는지 없는지 ( content difference ) 에 따라 relation extraction을 위해 사용되는 the methods와 resource에 영향이 있다네
> ????????

반면에,
community challenges는 계속해서 the development of state-of-the-art methods를 도와준다.

따라서,
각 카테고리에서,
우리는 they participate한 the challenge 를 가지고 있는 research work와 non-challege-participating한 research work로 묶었다.

그리고 우리는 algorithms들과 systems를 Table 1에 요약했다.

> ????????

_ _ _

#####Relation extraction from the scientific literature
오래전부터 계속적으로 biomedical leterature text로부터 semantic relations를 추출하고자 하려는 노력은 종종 NLP techniques에 접근하고 발전시키려는 shared-task community challenges의 형태에서 이루어졌다.

주목할만한 community challenges들은 
BioNLP shared tasks on mining,
BioCreative shared tasks on PPI extraction 
DDIExtraction challenges on DDI extraction
을 포함하고 있다.

우리는 these shared tasks에서 the semantic relations를 특징화 시키기 위한 graph-based techniques를 사용하는 팀들의 많아지는것을 확인할 수 있었다.

These techniques는 자주 성능이 가장좋은 축에 있었다.

This section에서는 these challenges를 위해 개발된 the graph-based methodologies 를 볼 것이다.

우리는 오직 the shared task proceedings 가 full publications로써 승인된 the papers만 고려할 것이고,
the top-performing systems에만 집중할 것이다.

우리는 the f-measures of the best systems in each shared task 를 a representative evaluation으로써,
그리고 독자들에게 the callenge overviews for detailed and comprehensive evaluations.

> ??????

아마 these challenges로부터 수업을 받는 것을 통해, 실제 세계의 적용 (the field of pharmacogenomics) 또한 graph-based textmining methods의 개발과정에서 중요한 모멘텀을 볼것이다.

> 아마 methods 제작과정에서 좋은 driver가 될 것이다 라는것 같음

우리는 약리유전학에서의 발전을 위한 this section의 마지막 부분에 헌신했으며,
biomedical relation extraction에서
methodology-oriented research 에서 application-oriented research 로의
graph-based algorithms의 변화와 적응을 보여준다.

> 그니까 방법론적 연구를 위한 algorithms에서 응용연구를 위한 algorithms으로 변경했구나.


######BioNLP event extraction shared tasks
Three BioNLP shared tasks (ST)는 the literature로부터의 biological events(relations)에 초점을 맞춰왔다
These tasks 는 the protein mentions를 input으로써 제공하고,
the participating teams 에게 미리정해진 set of semantic relations를 식별하라고 요구한다.
Teams 는 the protein mentios를 발견할 필요는 없다.

Three tasks로 구성된 BioNLP-ST-2009 
core event detection
event argument recognition
negation/speculation detection
(all based on the GENIA corpus)

BioNLP-ST-2011 expanded the tasks and resources to cover more text types, event types and subject domains

BioNLP-ST-2011 added the following tasks:
Besides the continued GENIA task (GE),  
epigenetics and post-translational modification (EPI), 
infectious diseases (ID), 
bacteria biotope (BB),
bacteria interaction (BI).

BioNLP-ST-2013 further expanded the application domains with
tasks of GE, BB, 
cancer genetics (CG), 
pathway curation (PC),
gene regulation ontology (GRO) [110]. 

Table 2 describes those tasks in more detail.

_ _ _

The typical event extraction workflow 는 Two general steps으로 나누어 질 수 있다.
Trigger detection
Argument detection

예를들어,
'[the patient] was put on [Imatinib regimen]' 이라는 문장에서
the first step detects the event trigger 'put',
the second step detects the theme 'Imatinib regimen' and target argument 'patient'


Bjo¨rne et al
stenteces를 the McClosky-Charniak-Johnson parser을 사용하여 a dependency graph (stanford Dependency)로 변환하였다.
그리고, both steps을 위한 features를 만들기 위해 the graphs를 탐색했다.

the McClosky-Charniak-Johnson parser는 the constituency parser of Charniak and Johnson을 기반으로 만들어졌으며,
the biomedical domain model of McClosky와 함께 retrain 되었다.

이 방법의 경우에는 arguments 사이의 the shortest path of syntactic dependency를 기반으로 하는 event arguments와 연결하는 n-gram features를 발생시킨다.

Their system TEES performed best in 
the 2009 GE (0.52 f-measure), 
2011 EPI (0.5333 f-measure), 
2013 CG (0.5541 f-measure), 
2013 GRO (0.215 f-measure, being the only participating system)
2013 BB full-event extraction (0.14 f-measure).


Hakala et al.
TEES system의 top 을 만들고 , 그것의 output을 enriched graph-based features에 의해 re-rank 시켰다.

여기서 enriched graph-based features란
외부 PubMed abstracts and the PubMed Central full-text corpus로부터 mined된 general subgraphs에서의
paths connecting nested events and occurrence of gene-protein pairs

> nested events를 연결하는 Paths와 gene-protein pairs의 발생

The system by Hakala et al. placed first in 2013 GE (0.5097 f-measure),
whereas the TEES system placed second (0.5074 f-measure).

graph-based features을 많이 사용하는 모든 systems의 strong performance 

특히, Hakala et al. 이 enriched graph-based features 와 obtained better performance (first vs second)를 이용해 Bjorne et al을 확장시켰다는 사실은

the potential benefits of exploring graph-based features을 보여줌.

> 기존의 방법을 이용하여 새로운 방법을 만들어냈는데 그것이 좋은 성능을 보이면서 relation extraction 분야에서의 exploring graph-based features가 좋은 방법임을 보여주었넹


_ _ _
Miwa et al.
the EventMine system을 만들었다.
이 the EventMine system은 biomedical events뿐만아니라 their negations and uncertainyt statements까지 추출해낼 수 있었다.

event extraction을 위해,
the Enju parser과 the GENIA Dependency parser(GDep)를 사용했다.

GDep는 dictionary based features와 함께 path features를 발생시키기 위해서!
(ex, UMLS Specialist lexicon and Wordnet)

Their entry in BioNLP-ST-2013 placed first in the PC task.

> 지금 이 내용들이 community challenge를 위해 제출된 연구들
> the PC task는 community challenge의 한 분야

특히,
their path features는 
paths between event arguments 뿐만아니라
paths between event argument and non-argument named entities 를 포함한다.

나중에 pahts들은
더 많은 local context features를 제공함으로써 strongperformance를 낼 수도 있다.

_ _ _

또 다른 event extraction으로 제안된 연구로는

동시에 예측된 같은 문장에서의 모든 events에 대한 trigers and arguments에서의 

> ????

McClosky et al.
event extraction을 the overall dependency parsing objective 로 통합시켰다.
They 은 the McClosky-Charniak-Johnson parser과 변형된 the parsers들을 Stanford Dependency에 적용시켰다.
그들은 training data에서의 the annotated event structures을 event dependency graphs로 변환시켰다.

>event dependency graph 는 
>event arguments (named entities)를 node로
>argument slot names를 edge로 둔 그래프이다.


They 는 the vent dependecy graphs를 Stanford Dependency graphs 로 매핑했고,
확장된 MSTParser을 test data로부터 event dependency graphs를 추출하도록 
train 시키기 위해 graph-based features를 만들었다.

Their graph-based features 은
the Stanford Dependency graph에서의 nodes간의 paths를 포함하고있고,
그들의 parents, childeren, siblings of the path nodes로 구성되는 subgraphs들도 포함하고있다.

그다음,
그들은 the top-n extracted event dependency graphs를 다시 event structures로 바꾸고,
the best one을 위해 event structures를 re-ranked 시켰다.
event dependency graphs로부터 같은 graph-based features를 사용하면서,

> event structure -> event dependency graphs -> event structures 구조구나

Riedel et al
먼저, Markov Logic Networks를 event structures 를 익히는데 적용시켰고,
후에 graph-based methods로 변경했다.

> ?

They 는 events들을 labeled graphs로 보여주었고,
event triggers and arguments들에대한 제약들을 잡아내는 function을 사용하여 candidate graphs에 대해 점수를 매겼다.

The scoring function은
token features,
dictionary features
dependency path features
을 고려한다.

더 나아가,
그들의 모델과 McClosky et al 에 의한 the system과 combine 하기 위해
a stacking model을 사용했다.

The combined system은 
first place in 
2011 GE task (0.56 f-measure)
2011 ID task (0.556 f-measure)
에서 얻어졌다.

_ _ _
경쟁적으로 수행된 most of the remaining BioNLP systems은 또한 
규모를 다양화 하기위해서 graph-based features를 사용했다.

> 규모를 다양화해?

Liu et al.
an Exact Subgraph Matching (ESM) method를 개발했고,
후에 more flexible Approximate Subgraph Matching (ASM) method를 개발했다.

그들은 the McClosky-Charniak-Johnson parser과 함께 sentences을 처리했으며,
the parses을 directed dependency graphs로 변형시켰다.

그들은 the graph of an event 를 만들었다.
by computing unions of dependency paths between event arguments

> event arguments 사이의 dependency paths의 unions을 계산함으로써 

그다음, 그들은
ESM/ASM를
sentence graphs 에서부터 event graphs까지 적용시켰다.
using a customized distance metric 을 사용하며,

>근데 distance metric는 
graph structure,
node-covered stemmed words
edge directionality
에서의 subgraph differences를 설명하는 것

그들은 그들의 메소드를 확장시켰다
Protein Data Bank(PDB)과 Uniprot 과 Biothesaurus를 통합함으로써 
protein/residue names을 인식하기 위해,

그리고 그들의 메소드를 BioInfer 과 Uniprot corpus를 포함하는 다른 corpora에 적용시켰다.

> 처음에는 PDB Uniprot Biothesaurus를 대상으로 하고 그다음에 다른 literature에 적용시켰넹

This work 는 this lines of graph kernel-based methos를 형성했다.

일반적으로,
kernel methods는 간접적으로 similarity function 에 가중치를 매기며,
features는 오직 instance pairs의 similarity function을 평가하는데만 사용된다.

따라서,
Kernel methods는 종종 직접적으로 weight/rank 할 수 없다. features.

> 왜냐하면 평가하는데만 사용되거든.


Kilicoglu et al.
또한 the McClosky-Charniak-Johnson Parser/Stanford Dependency pipeline을 응용했다.

> the McClosky-Charniak-Johnson Parser 되게 많이쓰네

그들은 the dependency graphs를

embedding graphs를 횡단하고, ( 탐색하고? )
nested events를 추출하기 위한
post-processing rules를 적용시키기 위해

embedding graphs 로 변환시켰다.

embedding graphs 란
nodes 자체 스스로 small dependency graphs가 되는것

그러나, their embedding graphs 는
argument erro propagation 과 부정확성이 발생했다.

> 실패 ㅠㅠ

_ _ _

가장 인기있는 McClosky-Charniak-Johnson Parser/Stanford Dependency pipeline 에 비해서

몇몇 systems 는 different parsers and/or dependency representations 와 함께 실험을 진행했다.

Hakenberg et al
BioLG (a Link Grammar Parser extension) 을 parser trees를 발생시키는데 사용했다.

그들은 parser trees를 database 에 저장시켰으며,
subgraph pattern에 사용하기 위해 query language를 설계 했다.

subgraph patterns은 수동적으로 parse trees에 대항하여 training data 로부터 만들어진것.

> parse tree가 뭐지

그들은 event types의 발생이 their result를 더 좋게 만들 수 있다는 점을 주목하였다.

> 하고싶은 말이 뭐지 

Van Landeghem et al.
the Stanford Parser로부터
training data와 these patterns 기반으로 만들어진 extraction rules 로부터 
minimal event-containing subgraph patterns를 식별되어지면서,
dependenc graphs를 분석하였다.

> 여기 해석 다시 해야 할듯?


Their post-procssing rules는 overlapping triggers of different event types 과 같은 trigger, trading recall for precision 기반한 events들을 다룬다.

_ _ _ 

The other systems는 일반적으로 event extraction을 위해 the dependency paths connecting the concept pair as features를
사용한다.

예를들어,
the dependencies 는 다른 parsers의 적용을 통해 얻어졌다.

parsers라고 함은, the Pro3Gres parser (Kaljurand et al.)
the RASP parser (Vlachos et al),
or both McClosky-Charniak-Johnson parser and Enju parser (Quirk et al) 를 말한다

그러나,
같은 Task에 있어서 이 메소드들 중 대부분은 비교적 좋지않은 성능을 보인다.
우리는 2가지 이유가 있다고 생각한다.

1. the McClosky-Charniak-Johnson parser with the self-trained biomedical parsing model 은 이 분야에서 가장 정확한 parser이다.
2. the best systems에 의해 사용된것 처럼 the enriched graph-based features and event type generalization event extraction에서 매우 유용한 features를 만들어 낼 수 있다.

######PPI extraction and BioCreative shared tasks

BioCreative shared tasks 는 
biomedical text에서의 genes and proteins에 대한 자동 named entityr recognition 과
이 entities들 사이의 the interaction을 추출하는 것에
집중한다.

the PPI task of BioCreative-2의 PPI task의 참가자 사이에서,
most of systems은 
co-occurrence statistics,
pattern templates,
shallow linguistic features (eg. context words and part-of-speech tags)
들을
statistical machine learning 이나 rule-based systems 과 함께
을 사용했다.

> 머신러닝 기법이나, 규칙을 기반한 분류기법을 사용했었어

Some of systems는 
the need for capuring cross sentence mentions of interacting proteins.
를 관찰했다

> 상호작용하는 단백질들을 언급하는 문장에 대해 capture할 필요성

예를들어, 

Huang et al.
a profile-based method 를 개발했다.

method :
the document의 mutiple sentences로부터의 features를 통합함으로써,
candidate protein pairs를 위한
a vector representation를 만드는 메소드

The Profile features은
n-grams
직접 구성한 templates
relative positions of protein mentions
를 포함하고 있다.

In BioCreative-2.5 에서
the top teams in the PPI task를 기반으로
the organizers는 deep parsing and dependency tree/graph mining 을 사용한
the BioNLP techniques들이 중요한 결과를 성취하는데 필요하다는 것에 주목했다.

특히,

Hakenberg et al.
their BioNLP-ST-2009 entry system 과 비슷한 system을 사용했었다.
그들은 직접 training date로부터 subgraph patterns를 만들었고,
subgraph patterns를 against parse trees에 match 시켰다.

Their f-measure was 0.30.

Saetre et al

the Enju parser and teh GDep parser 을 사용했고,
relation extraction를 위해 concept pairs사이의 the dependency paths들을 features로 고려하였다.

이 방법의 f-measure은 0.374 이다.



The PPI tasks of BioCreative-3 는
PPI-related articles를 찾아내는 것 으로 구성되어있다.

여기서 PPI-related articles란
특정 PPIs 에 대한 증거를 제공하지만, the actual extraction of PPIs는 포함하지 않는 article을 말한다

> 오 직접적인 PPIs 추출은 하지않지만, 특정 PPIs에 대한 증거를 제공해
> 네트워크를 구성하지않나?

Several follow-up studies to BioCreative-2.5 은
kernels in PPI extraction, based on corpora including AIMed, BioInfer ,HPRD50 , IEPA and LLL
의 사용을 평가한다.

Studies는 
kernels를 아래와 같이 카테고리화 한다.

(1) shallow linguistic (SL) kernels[140];
 
(2) constituent parse tree-based kernels, 
including subtree (ST) [141], subset tree (SST) [142] and partial tree (PT) [143] kernels that use increasingly generalized forms of subtrees, 
as well as a spectrum tree (SpT) [144] kernel that uses path structures from constituent parse trees; 

(3) dependency parse tree-based kernels, including edit distance and cosine similarity kernels that are based on shortest paths [145]
k-band shortest path spectrum (kBSPS) [99] that additionally allows k-band extension of shortest paths, 
all-path graph (APG) kernel [20] that differently weights shortest paths and extension paths in similarity calculation, 
as well as Kim’s kernels [146] that combine lexical, part-of-speech and syntactic information along with the shortest path structures.

> 한번 확인할것


The comparative studis and error analyses 는 이것을 보여준다.


> 위에것을 통해 연구ㅡㄹ 비교하고 에러를 분석해보면 이런 결과를 유추할 수 있따.

(1) dependency tree-based kernels generally outperform constituent tree-based kernels; 
(2) kernel method performances heavily depend on corpus-specific parameter optimization;
(3) APG, kBSPS and SL are top-performing kernels;
(4) ensembles based on dissimilar kernels can significantly improve performance; 
(5) non-kernel-based methods (e.g. rule-based method, BayesNet) can perform on par with or better than all non-top kernel methods.

이러한 관찰로부터,
이것은 richer dependency graph/tree structures (e.g. in APG, kBSPS) than shortest paths은
graph/tree-based kernels,which is consistent with the analysis of BioNLP participating systems,
의 더나은 퍼포먼스를 위해 중요하다는 것의 증거이라는 것을 보여준다.

> dependency graph/tree structures가 뭔가 더 정보가 많으면, 성능이 좋아지는구나.
> 2번 같은 뭐 그런거
> 의존한다는것 자체를 보여주네

The limited advantage of the kernel methods는
non-kernel methods와 kernel methods와 연관된 해석의 어려움을 넘어
새로운 kernel functions보다는 새로운 features sets을 조사하는데 더 존재하는것 같다.

######DDI extraction and DDIExtraction shared tasks
The two DDIExtraction Challenges (2001 and 2013)은 
biomedical text로부터 DDI의 자동추출을 목표로 하였다
The organizers of the two challenges들은 
직접 curated DDI databases를 업데이트 하는데 있어서
the extended delays를 발견했다.

> DB update에 어려움이 존재했대

그들은 the medical literature 와 technical reports가 the detection of DDIs에 가장 효과적인 sources이지만,
엄청난 양의 data를 포함하고 있는 단점을 가지고 있는것을 발견했다.

따라서,
DDIExtraction 은
Accurate automated textmining approaches를 위해 the pressing need에 의해 동기부여 되었다.

> pressing need 꼭 필요한 nees 라고 무난하게 해석하자

DDIExtraction-2011은 
candidate drug pairs 사이에 어떤 interaction이 존재하는지 안하는지 구분하는 것에 집중했다.

DDIEtraction-2013은 추가적으로 
detailed classification of DDI into one of the four possible subtypes 를 추구했다.

advice (advice regarding the concomitant use of two drugs), 
effect (effect of DDI), 
mechanism (pharmacodynamics or pharmacokinetic mechanism of DDI) 
int (general mention of interaction without further detail).




In DDIExtraction-2011,
Thomas et al
the McClosky-Charniak-Johnson parser/Stanford dependency pipline을 적용했다.
그들은 직접적으로 relation extraction을 위해 features를 잡아내기 위한 the follwing kernels 를 투표를 통해 통합했다.
APG [20], kBSPS [99] and SL [140] kernels.
Their best f-measure was 0.657.

Chowdhury et al
the Stanford parser를 dependency trees 를 얻어내는데 사용하고
relation extraction을 위해
feature-based methods와 kernel-based ensemble methods 둘다와 함께 실험을 진행했다.
그들은 
mildly extended dependency tree (expanding shortest paths to also cover important verbs, modifiers or subjects)
and path-encoded tree  kernels. (based on constituency tree) 
를가지고 SL 실험을 진행했다.

> SL ( Swallow Linguistics )

feature-based and kernel-based methods를 통합함으로써,
They achieved the second best f-measure of 0.6398

In DDIExtraction-2013,
그들은 r그들의 previous kernel method를 사용했지만,
그러나 the McClosky-Charniak-Johnson parser로 변경했고,
the parses를 Stanford Dependency로 변환하였다.
이 방법의 일반적 classification에서는 f-measure은 0.80이였고
이 방법의 구체적 classification에서는 0.65가 나왔다.

Thomas et al 경우 a two-setp approach를 따랐는데,
1. general DDIs를 감지하고
2. 그다음, 감지된 DDIs를 subtypes를 통해 분류한다.

the general DDI task를 위해,
그들은 kernels를 통합하는데 투표를 진행했다.

kernel : APG [20], subtree (ST) [141], SST [142], SpT [144] and SL [140] kernels.

For the subtype classification step,
그들은 직접저긍로 TEES를 사용했다.
Their system은 second best with an f-measure of 0.76 for general classification and
0.609 in detailed classification.

이것은 PPI extraction 이나 Event extraction을 위해 개발된 systems의 적용이 DDIExtraction에서도 최고의 성능을 나타낼 수 있는 흥미로운 결과도 보여준다.

이는 더 나아가 these tasks이 더 가깝게 연관이 있다는 것과,
한가지를 위한 technical solutions는 다른것에도 일반화 될 수 있다 라는 것을 보여준다.

> tasks 들이 서로 연관이 있으니까 한가지 메소드로도 서로 적용이 가능하다는것을 보여준 사례라고 볼 수 있겠다

######Pharmacogenomics

약리유전학에서는,
genetic mutations 와 drug response phenotypes사이의 흥미로운 관계들을 밝혀내기 위한
literature and clinical text의 사용을 중심으로 많은 노력들이 이루어 지고 있다.

비록 이것들의 성능은 서로 공유된 corpora를 사용하는것이 아니끼 때문에 비교하기 힘들지만,
이 approaches들은 
the translational application and
adaptation of some state-of-the-art biomedical relation extraction techiniques,
clinicians and pharmacologits에 의해 직접 요구되어진 문제들에 대한 

_ _ _

Some systems는 path-based approaches를 사용한다.

Coulet et al
pharmacogenomics를 위한 semantic networks를 만들기 위해
genes, drugs and phenotypes 사이의 binary relations를 추출하는 것에 집중한다.

> 네트워크 만들라고

They는 먼저, the Stanford Parser output on sentences (from collected PubMed abstracts)를
dependency graphs로 변환했다.

그들은 name entities로부터 시작하고 verbe에서 끝나는 path를 추적했다.

그들은 빈번한 relations 을 얻어냈고,
the collected entities와 relation types (verbs) 둘다 표준화했다.

relation types의 열거 순서를 요구하는 것 없이,
그들은 
의미론적으로 풍부한 rich summaries of pharmacogenomics relations 를 제공하는
a semantic network knwledge based 를 만들어냈다.
from 17 million MEDLINE abstracts, 

Percha et al.
the dependency graph에서 two named entities간 the shortest path를 산출해서
relation extraction을 위한 features를 발생시키기 위해
BFS를 사용하도록 this approach를
연장시켰다.

> this approach?

그들은 the extracted gene-drug relations를 DDIs를 추론하기 위해 통합시켰다
the same gene product와 함께 상호작용하는 those drugs들을 기준으로,

wang et al
잠재 Dirichl et al location을 a semantic representation of biomedical named entities 를 만드는데 사용했고,
Kullback-Leibler(KL)divergence 를 in the Chem2Bio2RDF semantic network에서의
pairs of entities 간의 the association distance를 계산하기 위해 사용했다.

그들은 candidate associations between named entitiy pairs를 summing distance along the path connecting the pairs 으로
서열을 나누었다.

그들은 새로운 knowlege discovery의 사용을 보여주었다.
searching and predicting novel gene-drug associations
traversing the mined semantic network to compare the molecular therapheutic and toxicological profiles of candidate drugs.

_ _ _

Other systems 는 tree-based approaches를 사용한다.

Katrenko et al
gene-protein relation과 protein-protein relation extraction을 연구하고,
the dependency parse trees에서
두 named entities들의 가장 가까운 공통조상을 뿌리로 하고있는
the subtrees를 features로 두고 있다.

Their experiment는 the Link Gramar Parser, Minipar and the Charniak Parser을 포함한 몇몇 parsers를 사용하고있다.

각각의 parser의 결과를 비교했을때,
그들은 
adopting ensembel methods (stacking and AdaBoost) 와
Combining multiple parsers' results의 통함으로부터
향상된 성능이 나오는것 을 확인했다.

Hakenberg et al
gens, SNP variants, drugs, ADRs사이의 relations를 추출하는 것을 목표로 하고있었다.
그들은 특정 relations의 추출을 위해 co-occurrence에 의존했다.
(e.g. gene-drug, gene-disease and drug-disease)
그러나 the Stanford Parser output for other types of relations로부터
subtrees와 함께 co-occurrence 증가시켰다.
but augmented co-occurrence with subtrees
from the Stanford Parser output for other types of relations.

그들은 binary relations 를 고려했고, 공통조상을 가지고있는 named entity pairs의 subtrees를 사용했다.

The mined relations are cross-referenced with knowledge bases including EntrezGene, PharmGKB and PubChem.

Bui et al
HIV drug resistance을 예측하기 위해 drugs and virus mutations 간의 관계를 추출하는 것을 목표로 했다,

그들은 Stanford Parser 를 constituent parse trees for sentences를 만드는데 사용했다.
그리고 그들은 drug-gene relations를 추출하기 위해 트리구조를 탐색할 수 있는 grammatical rules를 개발했다.
그들의 System은 연구에서 새로운 HIV drug resistance candidates을 먼저 선택하기위해 5개의 병원들에서 사용되고있다.

_ _ _

Pharmacogenomics에서 path-based systems 와 tree-based systems 은 
다수의 shared tasks에서 사용되는 the balanced f-measure와는 다르게 
그들의 평가에서 recall 보다는 precision에 더 집중하는 경향이 있다.

이는
pharmacogenomic semantic networks를 만들고 발전시킬수 있는
믿을만한 관계를 찾아내려고 하는 특정한 목표로부터 나온 것같다.

Too much noise는 초기 semantic network를 cloud 할 수 있다.
반면에, missing relations는 더 많은 literature를 사용함으로써 나주에 발견될 여지가 여전히 존재한다.

사실, 보고된 precisions for pharmacogenomics relation extraction system은
전형적으로 70%~80%이다.
게다가,
이 systems은 종종
PharmGKB와 같은 curated database로부터 반대되는 relations을 추출한다.

우리는 이 systems들이 
biomedical models로 parser들을 훈련시켜 적응시키고,
enriched grap-based features를 사용함으로써,
더 나은 이익을 줄 것으로 보인다.

위 두개는  two of the most recent lessons learned in shared takss. 이다.



#####Relation extraction from clinical narrative text

The medical informatics community는 또한 
확장적으로
shared tasks 와 seperately motivated research의 형태에서의
relation extraction을 연구한다.

예를들어,
EMRs의 narrative text으로부터의 semantic relations 추출에서 중요한 발전은
the i2b2/VA-2010 challenge 
(i2b2—Informatics for Integrating Biology to the Bedside,VA—Veterans Association)로
작성되어 왔다.

######i2b2/VA challenge
The challenge는 3가지 tasks를 가지고있다.
1.concepts extraction
2.assertion classification
3.relation classification, participated by numerous international teams.

Concepts extraction 는 
Assertion and Relations 모두 the extracted concepts로 표현되기 때문에
기초적 단계로 고려되어질수있다.

the challenge가 relation classification이 the ground truth of concepts extraction을 사용할수 있도록 허용하기 때문에,
relation classification의 the performance metrics는  an upper bound for the end-to-end relation extraction task
(same as the challenges from BioNLP, BioCreative and DDIExtraction)
로써 해석되어질 필요가있다.

In this section,

우리는 오직 medical problems, tests, and treatements 사이에서 the target relations 이 미리 정의되는 the relation classification system을 리뷰할 것이다.

이들의 relations들은 
‘treatment improves / worsens / causes / is administered for / is not administered because of medical problem’, 
‘test reveals /conducted to investigate medical problem’and
‘medical problem indicates medical problem’
을 포함하고있다.

위의 challenges를 리뷰함에 있어서 처럼,
우리는 단지 sentences를 그래프처럼 보여주고,
the feature-generation step 동안 such graphs를 탐험하는
those system 들을 리뷰할 것이다.

_ _ _

Robert et al.
꽤 포괄적인 set of features을 사용하여 the semantic relations를 분류했다.

context features (e.g. n-grams, GENIA part-of-speech tags surrounding medical concepts),
nested relation features (relations in the text span between candidate pairs of concepts), 
single concept features (e.g. covered words and concept types), 
Wikipedia features (e.g.concepts matching Wikipedia titles), 
concept bi-grams features
and similarity features.

> 이것들을 사용해서 분류했대

그후 GENIA pharse chunks and Stanford Dependency shortest paths를 포함하는 언어적 산물의 edit distance를 사용하여
computed 되었다.

Their system은 the hight f-measure on realtion classification 0.737에 도달했다.

deBruijin et al.
the relation distribution을 균형잡기 위해 적용된 down sampling 과 함께
a maximum entropy classifier을 적용했다.

그들은 the McClosky-Charniak-Johnson parser/Stanford Dependency pipeline을 사용했으며,
the concept pairs를 cover 하는 the minimal trees간의 the dependency paths를 feature로써 포함시켰다.

그들은 the problem of unseen words를 보여주기 위해 word clusters를 features로 사용했다
그들의 시스템은 the second best f-measure of 0.731에 도달했다.

Solt et al.
그다음 몇몇 parser 
includin the Stanford Parser, the McClosky-Charniak-Johnson Parser and the Enju Parser.
로 진행을 했다

그들은 
including the all paths graph(APG) kernel [20] and kBSPS [99], which produced only moderate performance
두개의 그래프 kernels와 함께
the resulting dependency graphs를 사용했다.

이것은 the graph/tree kernel-based systems 을 튜닝하는데 있어서 어려움을 보여준다.

the scientific literature로부터의 relation/event extraction에서의 the experience로부터의
일관된 관찰과 함께

######SemEval 2015 Task 14
The SemEval 2015 Task 14 는
disorder identification
disorder slot filling tasks
포함한다

Disorder identification is 필수적인 named entity detection 이며
Disorder slot filling task is BioNLP event extraction tasks 와 비슷하지만,
clinical subdomain에서 사용되는 차이가 있다.

더 나아가 The challenge the slot filling task를 두개의 subtasks로 나눈다.
one with gold-standard disorder spans (task 2a)
one without (task 2b)

따라서,
task 2b 는 task 2a에 비해 더 엄격한 평가 결과를 가진다.

The challenge에 의해 정의된 the attribute slots 은 

concept unique identifier (CUI)
negation (NEG)
subject (SUB),
uncertainty (UNC), 
course (COU), 
severity (SEV), 
conditional(CND), 
generic (GEN) and 
body location (BL).
를 포함한다

the CUI을 식별하는 것은 the named entity-detection problem 이다.
그리고, negation and uncertainty을 식별하는 것은 the assertion classification problem 이다.

SUB, COU, SEV, CND, GEN and B 을 식별하는 것들은 binary relation extraction과 더 유사하다.

그것들은
asthe challenge limited the possible values for those slots,
a layer of abstraction을 추가하면서,
완전하게 binary relation extraction과 동등하진 않다.

_ _ _
The challenge 는 
the participants의 서열을 나누기 위해
가중치가 적용된 accuracy를 사용한다.

Xu et al. and Pathak et al.은
일관성있게 
the top two teams in both task 2a (0.886 and 0.880, respectively)
and task 2b (0.808 and 0.795, respectively). 
서열을 나눈다.

Xu et al.
BL slot filling 을 위해
Conditional Random Field (CRF) 를 the classifier로 사용한다.

그리고 other slots을 위해
SVM을 the classifier 로써 사용한다.

추가적으로 The SVM classifier는 the disorder mentions의 into and out 에서의 dependencies를 사용한다.

these dependencies는 multi-hop syntax dependence를 잡아낼순없지만,
저자들은 that NEG/UNC/COU/SEV/GEN always have one-hop dependence 를 관찰한 것을 주목해라

반면에,
CRF (for BL) 는 그것 자체가 tokens 과 hidden staes 를 노드로써 사용하고
(integrating semantic and syntactic features including n-grams, context words, dictionaries and section names)
interconnects nodes with transition and emission edges 를 사용함으로써
로 graph-based model 이 된다.

Pathak et al.
slot detection을 두 부분으로 나누었다.

1.detecting keywords
2.relating keywords with disorder mentions.

그들은
bag-of-words 와 orthographic features to detect keywords와 같은 features로 훈련된 CRF과 함께 통합된
dictionary look-up ( 검색 ) 을 사용했다.

keyword를 disorder mentions와 연관짓기 위해,
그들은 Xu et al과 비슷한 features에다 Part-of-Speech tags를 추가적으로 사용하면서, SVM를 훈련시켰다.


Other teams는 간접적인 graph-mining algorithms을 사용했다.
그리고, 그러나 경쟁적으로는 사용되지않았다 ?

> ?

예를들어,

Hakala et al.

TEES system을 SemEval data foramt과 함께 작동될 수 있도록 적용시킴으로써 task 2a를 다뤘고,
3위에 해당하는 a weighted accuracy of 0.857를 성취했다.

이것은 주어진 many slot이 one-hop dependencies를 포함하고 있기 때문에, 놀랄일이아니다.
full-fledged graph-based approach는 오직 한정된 benefits를 제공한다.

게다가,
the controlled vocabulary and controlled format nature of challenge tasks는 그들 자체로
CRF에 맞게 만들어진다.
states and state-transitions의 한정된 숫자가 덜 빈약하고 더 튼튼한 probability estimation으로 이끌기 때문에,



######Separately motivated clinical relation extraction

After the i2b2 challenges,
몇몇 authors 는 the concept and relation extraction steps를 
통합된 pipeline and/or generalizing to the extraction of complx or even nested relations 로써 통합하는 것을 목적으로했다.

> 통합충~~

Xu et al.
a rule-based system MedEx을 만들었다.
이는, medications 와 그것들과 연관된 strenghs, routes and frequencies간의 특정 관계들을 추출하는 system이다.

The MedEx system은 narrative sentences in clinical notes를
conceptual graph representations of medication relations로 변환한다.

이것을 그렇게 하기위해,

Xu et al은 직접 conceptual graphs로 mapping 할 수 있는 a semantic grammar를 설계했고,
이 grammar에 따라 sentences를 parse 할 수 있게 the Ky Chart Parser를 사용했다.

그들은 또한
regular-expression-based cunker을 
the Kay Chart Parser가 놓친 medications를 잡아내는데 사용했다.


Weng et al.
a customized syntactic parser을 text spcifying clinical eligibility criteria에 적용했다.

그들은 maximal frequent subtree patterns를 추출했고,
직접 통합했으며,
그것들을 the UMLS와 함께 enrich 하게 했다.
a semantic representation for eligibiltiy criteria which aims to enable semantically meaning ful search queris over ClinicalTrials.gov 하기 위해.

Luo et al.
the Stanford Parser을 UMLS-based concept recognition과 함께
정확하게 graph representations for sentences in pathology report 하도록 발전시켰다.

여기서 pathology report란 the graph nodes가 medical concepts와 같은 것.

그 다음 빈번하게 나타나는 subgraph mining 은
medical concepts간의 중요한 semantic relations을 모으는데 사용되었다.
(e.g. which antigens are expressed on neoplastic lymphoid cells)
which serve
as the basis for classifying lymphoma subtypes.

Luo et al.
위의 the subgraph-based feature generation을 unsupervised learning으로 연장시켰다.

Luo는 더 나아가 tensor factorization을 subgraphs를 그룹짓기위해 사용했다.

The intuition (직관적 통찰)은 
각 subgraph가 test result와 일치하고,
subgraph group이 test 이 전형적으로 진단 가이드라인에서 사용되는 것처럼 a panel of test results를 보여주는것이다.

The tensors 3개의 차원을 통합했다.
patients, common subgraphs and individual word in each report.

The words는 subgraphs들을 더 낫게 group화 하는것에 도움을 준다.
lymphoma subtype diagnostic criteria 을 회복하는 것을 위해서


#####Shared resources for relation extraction

The shared tasks and separately notivated research on biomedical relation extracation은
오직 the state-of-the-art in methodology 발전한게 아니라
the utilzation of a repository of shared resources 를 만들고 보여주었다.

shared resources 는 knowledge bases 부터 shared corpora to graph ming toolkits까지의 범위.

우리는 카테고리화하고 요약해놓았다.
이 resource들을
Table 3에

미래의 연구 노력을 위한 resource navigation의 시작 포인트로써 제공되길 바란다.

Some of those resource는 일반적인 분야와 연관이 있다.
(e.g. general terminology/ ontology resources Wordnet [118], Verbnet [163]);

Some 은 포괄적으로 the biomedical domain과 연관이 있다.
(e.g. domain-specific terminology/ontology resources Gene Ontology [161], UMLS [58], Medical Subject Heading [162] and Biothesaurus [122]);

Some 은 target-specific biomedical subdomain
(e.g. knowledge bases such as PDB [101], Uniprot [121], SIDER [164], DrugBank [165], HIVDB [166], RegaDB [167], Entrez Gene [153], GENA [18]
and IntAct [169])


##### Lraod ahead
비록 graph-based algorithms을 the extraction of biomedical relations에 적용시킴에 있어서  주목할만한 과정들이 발견되었지만,
실용적인 relation extraction methods 를 개발하는데 있어서 장벽은 generalizable and sufficiently accurate 이다.

> 일반화와 그리 높지않은 정확성
 
밑에 우리는 몇몇 장벽과 이를 극복할 수 있는 잠재적인 방향에 대해서 설명해놓았다.

#####Not all parsers and dependency encodings are synergistic
#####모든 parsers와 dependency encodings는 synergistic 한것은 아니다.
반복적으로 the choice of the parser and dependency encdoings 는 relation extraction system's performance에서 중요한 역할을 할지도 모른다는 것은 주목 할만한다.

Buyko et al.
the impact of graph encoidng based on different parser 
(Charniak-Johnson, McClosky-Charniak-Johnson, Bikel, Gdep, MST, MALT)
and dependency representations  에 대한 compative analysis를 수행했다.
(Stanford Dependency and CoNLL dependency).

그리고 
the CoNLL dependency representation 이 
the Stanford Dependency representations보다 4개의 parser를 통합해서 사용하는 것에있어서
더 나은 성능을 보여준다는것을 발견했다.

그리ㅗㄱ
McCLosky-Charniak-Johnson parser 은 빈번하게 가장 성능 좋은 parser이기도 했다.

Miwa et al. 같은경우
BioNLP-ST-2009 를 위해 five syntactic parser 를 비교했다.

그들은
비록 각각 parsers를 사용하는 것으로부터의 성능은 크게 차이나지않지만,
parsers 여러개를 쓰거나, 다른 dependency representations를 쓰는것은 the event extraction results를 크게 향상시킬수 있다고 결론지었다.

> 혼합해서 쓰는게 좋다고하네여

Stanford Dependency 는 the most wideely used dependency encoding 이기 떄문에,
그들은 또한 이에대해 다양한 다른 Stanford Dependecy variants들을 사용하였고,
만약 dependency edges의 types가 유지된다면  basic dependency 가 최고성능을 보인다는 것을 발견했다.

반면에,
만약 types of dependecy edges를 무시한다ㅕㄴ,
그들은 the collapsed dependency variant 가 최고의 성능을 보여준다는것을 발견했다.

Luo et al 에 의해 밝혀였다.

In [49] 에서,
the task 는 relations를 lymphma subtypes를 분류하기위한 features로써 추출하는 것이였다.
in the BioNLP_ST event extraction tasks에서 superviesed relation classification에서 처럼
그들 자체를 분류하는것 대신.

따라서, recall은 the feature learning step에서 관심이 있는 것이 되었다.
the feature learning step이란 types of dependencies를 무시하는 것이 the coverate of subgraph patterns 향상에 도움을 주는것,

이를 통해서 배운 The lessons은 각 challenges로부터의 top participants로부터 각각 reports들이 확립된 것처럼 보인다.

그리고 The lessons들은 parser-dependency choice의 인기와 함께 consistent 이다. 
non-challenge applications in sections Pharmacogenomics and Sepearately motivated clinical relation extraction.

특히,
우리는 good combination은 the McClosky-Charniak-Johnson parser 나 Stanford parser augmented with medical lexicon 으로부터 선택하는 것이라고 기대한다

그리고 either CoNLL dependency or collapsed Stanford dependency 으로부터 선택하느 ㄴ것.


Intergrating coreference resolution
Coreference는 빈번하게 biomedical literature 나 clinical narrative text에서 발생한다.
the same concepts을 위해 prounouns, anaphora and varied entities의 사용으로부터 발생하면서,

Care must be exerciesd to transfer the correct relation along the coreference chain.


그러나, relation and event extraction을 위한  Many of the reviewed approaches는 a built-in coreference resolution component를 가지고 있지않다.

Miwa et al
구체적으로
the impact of using a coreference resoulution 에 대해 연구했고,
improved event extraction performance 를 보여주었다.

특히,
그들은 a rule-based coreference resolution system을 개발했는데.
이는 detecting rules for mextion antecedent and coreferential link로 구성되어있다.

그들은 
the coreference information을 syntactic parse results를 조절하는데 사용했다
antecedent and mention share dependencies


Features는 또한 확장되었다 between mentions and antecedents.

the importance of coreference features를 recognizing 하면서,
그후에 몇몇 systems는 across sentences 하여 coreference resoulition 을 보충했다

그들은 relations의 특정 types을 추출하는 것을 촉진하기 위해,
heuristic/rule-based coreference resoulition이 domain-adapted statistical machine learning systems를 능가하는 경향이 있다는 것을 보여주었다.

Part of their lessons 는 in relation extraction corpora에서 the lack of gold-standard coreference anotation을 걱정했다

따라서,
우리는 기대한다.
paired relation and coreference annotations 는
coreference resolution and ultimately relation extraction 을 향상시킬수 있다는 것을.

게다가,
coreference resolution을 the learning objective of relation extraction에 통합하느 ㄴ것은
더 포괄적인 최적화와 더나은 end-to-end performance로 이끌지도 모른다.



######General relation and event extraction and domain adaption

최신 relation and event exttraction systems from shared tasks 는
대부분 around domain-specific definitions of relations and events, many of which are in fact binary (PPI, DDI) and i2b2/VA challenge
이다.

> 그니까 요즘 relation and event extraction system은 모두 일반적으로 사용할수 있는 툴이 아닌 특정 분야를 대상하로 한 툴.

그러나,
the technical advances and the demands from many rea-world tasks 사이에는
pharmacogenomics semantic networks를 만들고,
clinical trial eligibility criteria 를 추출하고,
test results for automating diagnosis categorization을 보여주는데 있어서,
gap이 존재한다.

> 무슨 차이가 존재하지

In those tasks,
general relation and event discovery는 필수적이다.
where nodes의 숫자가 때때로 바뀔수있고,심지어는 the relation/event structure가 전체적으로 prespecified 되어있지 않을지도 모른다.

> relation event structure가 우리가 모르는 특정한 것에 대한 relation/event일 수 있다라는 거지

the automation of annotaion scheme learning or unsupervised relation extraction을 탐색하는
Systems는 일반화 하려는 시도를 했었다.
그러나 여전히 accuracy를 증가시키는데있어서 큰 여지가 존재한다.

Another challenge는 domain-specific relation/event definition에 의해서 가져온 것인데,
Another challenge는 the training data를 염려한다.

> ? 무슨 뜻이지

THe problem of limited training data 는
종종 NLP systmes의 개발을 괴롭힌다.
the relation extraction systems는 예와가 없다.

더나은 존재하는 annotated corpora의 사용을 만들기위해,
domain adaptation from external training corpora(source) to the target corpora를 수행하는 것은 필수적이다.

> 외부의 training corpora를 the target corpora로 적용시키는 것이  뭐하는걸까

단지,
top systems 을 the new format에 adapting 하는것과
training on the new corpora 하는 것은
새로운 분야에서의 top performers로 이끄는 것은 아니다.

> ?/

예를들면, the adapted TEES system in SemEval 2015 Task 14

Miwa et al은
adding
source instances followed by instance reweighting when source
and target match on events to be extracted.

When source and
target corpora have a partial match on events,
그들은 각 event extraction module을 분리적으로 train 시키는 것을 제안했었다. on the source corpora
그리고 
이것의 output을 additional featrues로써 사용했다. for the corresponding modules on the target copora.

더나아가 Miwa et al.
가짜 negative examples를 걸러내는 heuristics를 통합함으로써,
corpora를 combining 하는것의 methods를 향상시켰다.

The heuristics 은 에러를 맞추는데 목적이 있다.
이 에러는 where instances with a ‘None’ annotation
in one corpus owing to a different focus are all treated as negative
instances in the combined corpus.

7개의 event-annotated corpora로부터 learning에 method를 적용시키면서,
그들은 two tasks에서 향상된 성능을보여주었다.
BioNLP-ST-2011에서,

The successes from cascaded training and example filtering heuristics illuminate some promising directions in corpora adaptation. We expect parallel efforts in system generalization
and corpora adaptation can complement each other toward
effective domain adaptation.

Redundancy in subgraph patterns

