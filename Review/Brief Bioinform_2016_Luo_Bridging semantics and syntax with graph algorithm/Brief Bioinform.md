###Introduction
지식을 나타내고, 구조적 knowledge bases를 추론하고, 질문을 답변과 decision making으로 만드는데 있어서,
docuemnts로부터의 Relation extraction은 매우 중요한 task 이다.

The task는 일반적으로 
1. 구조화되지않은 문서에 named entities 와 함께 annotating하는 것
2. these annotated entities사이의 관계를 식별하는 것
을 포함하고 있다.

최신 Named Entity Recognizer는 높은 정확성으로 자동으로 text에 annotate 할 수 있다.
그러나 relation extraction은 직접적으로써 annotate 하진 않는다.

일반적인 domain relation exraction은 몇년동안 활발한 연구 분야였다.
In the biomedical and clinical domain 분야에서
scientific pulbications and clincal narratives에서의 extracting relation은 지난 몇십년동안 끌려와졌고, 이 Review의 주제가 바로 이것이다.

<hr/>

biomedical relation extraction의 중요성을 보여주기 위해,
lymphmoma pathology reposts에서의 immunophenotypic features가 medical concepts사이에서 관계로써 표현된다는 것을 고려해야 한다.

예륻들어, 
in '[large atypical cells] 가 
[CD30]에 대해서 positive 이고
[CD15]에 대해서 negative 인 상황에서,
'large atypical cells'와 'CD30', 'CD15'는 medical concepts라고 보는 것이다.

'CD30'과 'CD15' 는 cell surface antigens
> cell surface antigens : 세포 표면 항원

A bag-of-words나 bag-of-concepts representation은 'arge atypical cells'가  'CD30' 과 'CD15'에 대해서 positive인지 negative인지 잡아내는데 실패 할 것이다.
> bag-of 는 방법 중 하나인데, co-occurrence처럼 되게 단순한 거 같음
>  찾아볼것

In this and many other similar cases에서,
the biomedical concepts는 유의미해지고, 이 컨셉을 문맥에 넣음으로써 애매모함을 해결하기 위해
syntax 나 semantics와 연결 될 필요가 있다.

> put them into context 란 그냥 앞 뒤 상황을 고려하여 애매모함을 없애려는 시도 같음.

<hr/>

In this article,
we define
a relation as 
a tuple r(c1,c2,...,cn), n > 2 
where c's are concepts(named entities)
where c's are semantically and/or syntactically linked to form relation r, as expressed in text.

따라서,a single named entity는 일반적으로 relation으로써 간주되지않는다.

다시말해,
a relation은 적어도 two concepts를 포함하고 있다.
만약 n is 2(three)이면, the relation을 a binary(ternary) relation으로 부르며,
일반적으로 n-ary relation이라고 부른다.

몇몇 researchers은  binary relations를 나타내는 triples을 말하는 the term relation을 사용한다.

	ex) 
	positive-expression (large atypical cells, CD30),
	negative-expression (large atypical cells, CD15)

<hr/>

또한, events로써 종종 언급되는것을포함하는 the term relation 를 사용하기도 한다.

	the ternary relation treated_by (patient, Imatinib regimen, 5 months)

위 문장은 [the patient] was put on [Imatinib regimen] for [5 months]로 해석될 수 있으며,
the event trigger is 'put'
the theme is 'Imatinib regimen'
the target argument is 'patient' 
인 상황을 나타내는 것이다.

> Imatinib 는 글리벡 이라는 항암제를 나타내며, regimen 은 regimen이란 원래 두가지 이상의 항암제를 병합한 요법을 말하는데, 사용되는 항암제의 이름과 용량, 투여횟수, 간격 또 넓은 의미에서는 보조 약물의 투여 스케쥴도 포함된다고 할 수 있다. 엥 완전 이거 EMR 아니냐

Nested
events may occur when one event takes other events as arguments;

######Figure 1
Figure 1은 two argument events를 가르키는 solid and dashed boxes와 함께 내포된 event로써 해석될 수 있는 더 복잡한 예시를 보여주고 있다.

In computational linguistics,
events는 종종 어휘 요소, 논리적 의미, 그리고 문법을 통합하는 grammatical objects로 정의될 수 있다.

Firgure1은 binary relations, n-ary relations, 서로 긴밀해 연결되어있는 nested event와 event을 보여주고 있다.

State-of-the-art methods section에서 보여줄 것 처럼,
extracting relations and events를 위한 the NLP techniques은 종종 비슷한 원리를 보일 것이다.


따라서, 이 논문에선 relation과 event의 extraction을 포함하고 있으며,
we use both ‘relation’ and ‘event’, with the choice made to be consistent
with the literature being referenced.

<hr/>

The representation of relations는 수십년동안 다양한 대안과 함께 a subject of knowledge representations research 를 가져왔었다.

첫번째 대안
One representation에선 simple logical forms이 사용되었다.

예를 들어,
Resource Desription Framework (RDF) 나 Web Ontology Language (OWL) 는
by multiple triples 

encodes complex relations by multiple
triples, where the elements of these triples can themselves
be other composed forms.

따라서, binary relations such as positive-expression (large atypical cells, CD) 는 subject-predicate-object triple representaion이 따라온다.
: large atypical cells-positively express-CD30.

두번째 대안
A more powerful alternative는
the sentential logic(or propositional logic) respresentaion 이다.
논리적 연결성을 이용하는 representation
in which relations are propositions or
composed propositions using logical connectives (e.g. ‘and’ for
conjunction, ‘or’ for disjunction).

RDF triple과 비교했을때
propositional logic은 connectives and inference rules과 같은 추가적인 구성을 가지고 있다.
따라서 더 expressive 하다.

세번째 대안은 nodes이 named entities이고, edges가 relationships을 가리키고, 여러 edges에 의해 multiple named entities 를 나타내어 하나의 relation으로써 간주될 수 있는 the graph-based representation 이다. ( Figure 1 같은 거라고 한다 )

<hr/>

이 review는 graph-based representations을 사용하는 NLP methods과 unstructed text에서부터 biomedical relations를 추출하는 알고리즘에 초점을 맞출것이다.

alternative representations로 간주하면서, the sentential logic representation은 graph based representation과 함께 주목되어 질 수 있다.

Biomedical relations 는 
biomedical concepts를 nodes로 
syntactic/semantic links를 edges로 converting 함으로써
그래프 형태로 범용적으로 보여질 수 있다.

다른 propositional representations은 아마 그래프의 구체적인 해석이 필요할 지도 모른다.

예를들어,
proposition의 부정을 나타내는 것은 nested graphs의 도입이 요구 될 수도 있고,
특별한 semantics에게 NOT 이라는 Labeled relation 을 주도록 요구 받을 수 있다.

게다가, 비록 구성이 복잡해지더라도 ( n-ary relations 나 nested relations 같은걸로 )
graph-based representation에 적응됨으로써, 우리는 common syntactic and relations들을 식별할 수 있는 좋은 방법을 제공하는 semantic graphical patterns 에 집중할 수 있다.

> 구성이 복잡해지더라도, 주 목표인 syntactic와 relations를 찾는데에는 좋다는 말같아.

사실, 이 논문에서 후에 명확하게 될 것처럼,
extracting relations를 위한 거의 모든 최신 메소드들은 graph-based이다.

이 article은 the reader가 biomedical NLP에 대한 기본지식을 가지고 있다고 가정하고 있다.
시작 and 최근 응용프로그램에 관한 조사를 위해 See [7-12]

<hr/>

독자들은 또한 a body of research on curated structured knowledge bases에 대해 알고 있어야한다.
'전문가에 의해 작성된 biomedical relations에 대한 annotations와 함께'

Some of these knowledge bases 는 biologically focused 되어있다.
such as KEGG, STRING, InterPro and InterDom

몇몇을 뺀 나머지 것들은 더 clinically focused 되어있다.
such as PharmGKB, VARIMED,and ClinVar

그러나 the expert soucing methods는 종종 기하급수적인 biomedical free text의 성장과 함께 성장형편없게 평가한다.

> 뭔소리야 이게

따라서, 자동화된 methods은 existing knowledge bases를 늘리기 위하여
discovering relations를 위한 유망한 방향을 보여준다.
이는 이 this article에서 언급되는 많은 methods들에게 동기부여한다.

#####Application of biomedical relation extraction

Extracting biomedical relations 는 기초 과학의 발전부터 임상치료의 향상까지 많은 적용 방법이 있다. (Figure 2처럼)
이 적용 방법들은 
biomolecular information extraction,
clinical trial screening,
pharmacogenomics,
diagnosis categorization
에만 한정짓는 것이 아니라,
discovery of adverse drug reactions (ADRs) and drug-drug interactions (DDIs)도
포함하고 있다.

 - Biomolecular information extraction
The literature의 잠재적 성장을 계속 이끌어내기 위해,
automated methods는 
mining 
PPIs(Protein-Protein interactions),
gene-phenotype associations,
gene ontology and pathway information, which we colectively call biomolecular information extraction.
dp 적용되어왔다.

Such relation mining has shown its value in the prioritization of cancerous genes for further validation from a large number of candidates

Many of these approaches은 novel disease-gene relations를 예견하는데 사용되는 literature으로부터 잘 알려진 disease-gene relation을 추출하기 위해 NLP methods를 사용한다.


 - Clinical trial screening
Archived clinical and research data 는 정부기관이나 기업에 의해 사용할수있게 되었다.
ex) ClinicalTrials.gov

Clinical trials는 큰 부분에서 관계를 통해 잡아낼 수 있는 적격 기준에 의해 특징화 시킨다.
(e.g. no [diagnosis] for [rheumatoid arthritis] for at least [6 months])

Electronic screening 은 clinical trial recruitment에서 효과를 증가 시킬 수 있고,
trials를 넘어 intelligent query는 clinical knowldge curation을 도울 수 있다.

최근에는, NLP support는 eligibility criteria를 통한 automatically detecting named entities 를 통해 더 유용하다는 것이 입증되어 왔고, 더 나아가 extracting relations between named entities to characterize eligibility criteria 에서도 입증되어 왔다.

 - Pharmacogenomics ( 약리유전학 )
Pharmacogenomics는 drug response phenotypes 와 patient genetic variations 사이의 관계를 연구하여, patients가 얼마나 drugs에 다르게 반응하는 지를 이해하는데 목적이 있다.
이 약리유전학에 대한 많은 지식은
scientific literature 에서부터 mine 될수있고,
new relationships를 새로 발견하게 할 수 있는 DB에서 curated 할 수 있다.
그 DB의 예로 the Pharmacogenetics Research Network and Knowledge Base (PharmGKB)가 있다.
PharmGKB에 정보를 담기위한 최초의 노력으로는, expert annotation과 rule-based approaches 의 a mixture를 포함시키는 것이다.
최근 approaches 은 semantic and syntactic analysis 와 statistical machine learning tools,scientific literature와 clinical records로부터 targeted pharmacogenomics relations를 추출하기 위한,을 사용하면서 확장 되어가고 있다.

<hr/>

 - Diagnosis categorization
Diagnosis categorization 은
automated billing 과
추후의 patient cohort selection
을 가능하게 한다.
Developed systems는 자동적으로 EMR로부터 diagnoses를 code and classify할 수 있다.
최근 연구는 semantic relations의 성공을 보여주었고,
이 semantic relations 를 diagnosis categorization에서 additional features으로써의 사용을 보여주었고,
Some 은 curated relations를 사용하는 더나은 grouping features를 사용했고,
Others 는 medical concepts사이의 more expressive representation of relations 를 추출하기 위하여 unsupervised learning 을 사용했다.

<hr/>

 - ADR and DDI ( Adverse Drug Reaction, Drug Drug Interaction)
ADR은 약을 섭취함으로써 야기된 예상치못한 부상를 말한다.
DDI는 a drug가 동시에 투여된 다른 약과의 활동에 영향을 줄때 발생한다.

ADR는 병에걸릴확률과 사망할 확률의 중요한 원인이다.
DDI는 drug 효능의 감소나 drug 과다복용을 야기시킬지도 모른다.

이 잠재적인 ADRs과 DDIs 를 감지하는 것은 the process of drug development과정을 도울 수 있다.
많은 증가하는 methods들은 the scientific literature and clinical records에 NLP를 사용하는 것에 영향을 주었다.

These systems는 종종 drugs, genes and pathways, 텍스트로 적혀있는 ADRs과 DDIs의 발견 사이의 관계들을 종종 탐색한다.
최근, 많은 연구들은 또한 ADRs를 감지하기 위한 user-generated content in social networks 를 탐색한다.
최근 연구인 [57]가 있다.

<hr/>

#####General pipline for biomedical relation extraction

In Figure 3,
the reviewed approaches로부터 요약된
a general pipeline을 볼 수 있다. as a cookbook to follow either in part or as a whole for extracting biomedical relations

The reader can refer the components discussed in the state-of-the-art methods to this cookbook to gain comprehensive understanding.

For completeness,
document를 input으로,
extracted relations를 output으로 가정한다.

The pipeline은 section recognition으로 시작한다.
section recognition이란 다른 headings 하에서 text를 구분하는 것을 말한다.
ex) Chief Complaints or Past Medical History

그다음 Sentence breaking은 a paragraph에서 sentences의 시작과 끝이 어딘지 구분한다.

Typographical analysis 는 features ( Capitalization and usage of alphanumeric characters )를 조사한다.

이 Stemming (나누는 과정)은 the inflected words to the root form으로 변화시킨다.
ex) perfomed to perfom

> inflected : 어미 변화를 거친

POS tagging은 문장에서 각 each word 에 대해 a part-of-speech tag를 정렬한다.
ex) VBN for 'performed' in the sentence in Figure 1

Parsing은 a syntactic structure을 a sentence로 정렬하는 과정이다.
ex) the constituency or dependency structure obtained by Stanford Parser)

Typographical analysis, stemming, POS tagging and parsing 으로부터 얻어진 결과들은 recognizing anaphora (coreference resolution) and typed concepts (concept recognition)을 위한 features를 제공한다.

Coreference resolution 과 concept resolution은 또한 parsing accuracy를 향상시킨다.

Parsing과 함께, In the graph representation, a sentence와 labeling semantic roles of concepts를 위해 the graph representation의 발생단계에서 위의 과정들은 필수적이다. (Semantic Role Labeling)

The graph representation은 graph mining을 위한 기반이며,
direct regular expression feature extraction을 포함하는 upstream steps와 함께,
the generation of semantically and syntactically enriched features로 이끈다.

그다음, These features는 either rule-based, feature-space-based or kernel-based relation extraction system을 지원한다.

많은 biomedical relation extraction systems은 외부 지식 source에 의존한다 ( UMLS같은 )

<hr/>

The pipeline은 또한 downstream applications의 기반으로써 사용될 수 있다.
ex) Logical inference with extracted relations

The pipeline covers steps for breaking the documents to
sentences, understanding the semantic and syntactic structures
of sentences and constructing a multitude of features for relation
extraction.

우리는 the reader 에게
Figure 3의 캡션에서 each step에서의 설명을 언급해놓았다.

우리는 in the pipeline the role of graph mining 을 central concept으로써 강조한다.

The mined graphs는 local featrues ( tokens and part-of-speech tags ), a diverging point where more intergrated features ( relations as features ) are constructed, and a bridge to connect the syntax and semantics 를 포함하는 methods를 위한 convering point를 제공한다.

<hr/>

#####Introduction to graph representations and graph algorithms for biomedical relation extraction

Narrative sentences 을 위한 Graph representation은 자연적으로 nodes and edges로 표현되는 the choice of information 으로 구성된다.

Common node choices 는
tokens
named entities
senmantically labeled named entity
and relations themselves within nested relations.
를 포함한다.

Those choices are in
the order of encoding increasingly enriched and complex semantic
information.

Common edge choices 는
syntactic dependency,
syntactic constituency link,
event argument,
association
같은것을 edge로 본다.

These choices는 
semantic and syntactic information을 the graph representation 에 통합시킨다.
to different degrees.

Graph mining algorithms은 직접적으로 relations를 추출하기 위해 적용될 수 있고,
useful featrues를 구성하기 위해 적용될 수 있다.

빈번하게 사용되는 알고리즘은 다음에 따라 분류 할 수 있다.

Some identify shortest path (or its variant) between concept pair ( 다익스트라 같은 기본적인 알고리즘을 사용해서 수행될 수 있는 알고리즘)
Some create association graphs then try to apply customized labels to them.
Some use subgraph matching to compare the similarity between subgraphs based on a score that aggregates node distances and edge distances
some carry out frequent subgraph or subtree pattern mining to directly extract candidate relations
some directrly parse graph representation of relations from sentences by intergrating the graph structure into the learning objective of the parsers.

다음 섹션에서 state-of-the-art methods를 review할때,
우리는 각 method를 특징화 할 것이다.

along the axis of graph-encoded information
graph algorithms and intended usage

위 사항들을 Table 1에 요약해놓았다.

---------------------------------------------------------