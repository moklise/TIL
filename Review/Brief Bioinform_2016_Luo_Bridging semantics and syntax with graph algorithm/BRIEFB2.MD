
####Introduction to graph representations and graph algorithms for biomedical relation extraction

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

<hr/>

####State-of-the-art methods for biomedical relation extraction

Biomedical relation extraction을 위한 방법론은 높은 관심을 받아왔다.
Conventional approaches는 co-occurrence statistics를 관련성을 위해 사용 한 것에 초점을 두고있다.
> 많은 방법들이 co-occurrence statistics로 relation을 찾았나보네

몇몇 Clinical NLP systems는 직접만든 syntactic and semantic rules를 미리 서술된 semantic relations를 추출하는데 사용했다.
such as MedLEE and SemRep
그러나 이 clinical NLP systems는 새로운 subdomains에 적용시키기가 어렵다.
> 서브도메인 다른 분야에서 사용하기가 어렵다 뭐 이런거같은데
> 응용하기가 어렵다?

최근 영구는 syntactic parsing에 더욱 더 초점을 두고 있다.
'relation을 추출하기 위해 자연어의 constituency and dependency structures를 충분히 탐색하고 일반화 할 수 있는 메소드를 개발하기 위해'
> 여러 'subdomain,분야' 에서 사용할 수 있고 성능이 보장된 메소드를 만들고자 하였나보넹

In this section, we review the state-of-the-art approaches where graph (including tree) mining techniques are used to derive relations from syntactic or semantic parses.

우리는 메소드들을 카테고리화 했다.
그것들의 문서가 주로 scientific publications or clinical narratives와 연관이 있는지 없는지에 따라. 왜냐하면 그 content difference가 the methods와 resources used to extract relations 에 영향을 종종 미치기 때문에.

> ????????

반면에,
community challenges는 계속해서 the development of state-of-the-art methods를 도와준다.

따라서,
각 카테고리에서,
우리는 they participate한 the challenge 를 가지고 있는 research work와 non-challege-participating한 research work로 묶었다.

그리고 우리는 algorithms들과 systems를 Table 1에 요약했다.

> ????????

<hr/>

#####Relation extraction from the scientific literature
오래전부터 



######BioNLP event extraction shared tasks
Three BioNLP shared tasks (ST)는 the literature로부터의 biological events(relations)에 초점을 맞춰왔다

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

