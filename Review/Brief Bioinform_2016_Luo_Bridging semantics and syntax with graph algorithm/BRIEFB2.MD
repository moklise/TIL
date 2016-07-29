
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

######PPI extraction and BioCreative shared tasks

######DDI extraction and DDIExtraction shared tasks

######Pharmacogenomics

#####Relation extraction from clinical narrative text

######i2b2/VA challenge

######SemEval 2015 Task 14

######Separately motivated clinical relation extraction

#####Shared resources for relation extraction

> 그 Figure 2에서 <-> , Relation extration해서 얻은 데이터를 공유하기 위함.
> 뭔내용이지 

