###Results and discussion

The optimal tuning parameters and the statistical results for all the binary classification models 은 
모두 Table 3 에 요약되어있다

RF 은 모든 3가지 Features 에서 SVM를 능가하는 결과를 보여주었다.
RF 와 SVM 모두 일관된 순위를 나타내었다
Feature 3 > Feature 2 > Feature 1

The similarity neighboring links는 
RF에서 5.5% 까지의 성능향상을 보였고,
SVM에서는 4.4% 까지의 성능향상을 보였다.

In combination with RW normalization 에서는
RF에서 2%까지의 향상을 보였고
SVM에서는 3.5%의 향상을 보였다.

#####Fiqure 2


이 성능향상의 차이점은 Fig.2 에서 ROC and PR curves를 통해 확연히 드러난다.

> FEATURE간의 차이보다 RF 와 SVM의 차이를 강조하고 있네

The ROC space and PR space agreed on the rankings of different features set, in terms of predictive perfomance.

feature set 3 가
ROC모델이든, PR 모델이든 RF, SVM 모두에서 우위를 차지하는 것을 볼 수 있다.
그리고 RF 모델이 SVM 모델을 약간 능가하고 있다.

우리는 positive  와 negative labels의 균형잡히지않은 분산을 가지고 있기때문에,
PR curves는 성능 예측 차이에서 차이를 발견하는데 ROC curves보다 더 나은 시각적 요소를 제공한다.

> 간단하게, 
> Precision은 맞다고 생각하는 것 중, 정말 맞은것. TP / TP + FP
> Recall은  실제 시도중 맞은것. TP / TP + FN

Fig 2 에서 보인것처럼
the ROC curves는 가깝게 모여있고,
the PR curves에서는 크게 분리되어있다.

#####TABLE 4


Table 4
AUCPRs 사이에서의 차이들은 AUCROCs사이의 차이보다 크다.

similarity neighboring links 는
semantic network에서 link prediction를 예견하기 위해 중요하다는 것은 명확하다.

그리고 RW normalization은 feature space를 enriching 함으로써 predictive performance를 향상시킬 수 있다.

모든 the machine learning models이
over-fitting없이 tarining and test sets에서 잘 작동 되는 것은 눈 여겨볼만 하다.

> over-fitting이 없다? -> 모든 데이터들이 비슷비슷하다?
> 

게다가, feature set 2 and feature set 3의 AUCROCs는 SLAP에서 나온 수치인 0.92보다 더 크게 나왔다.

그러므로, meta-path-based topological features 은
machine learning models을 사용한
complex semantic networks에서 link prediction할 가치가 있다는 것을 입증했다.

<hr/>

##### Table 5	
// This approach와 SLAP를 비교하기 위해, AUCROC과 BEDROC를 이용한다.


지금 제안한 approach와 SLAP을 비교하기 위해
an evolving semantic network의 unknown links의 a large set에 이 메소드들을 사용하는 link predictions을 수행하였다.

Chem2Bio2RDF network가 구축된 이후, PubChem BioAssay databases에 저장된 experimental evidence로부터 이 unknown links에 대한 labels을 가져왔다.

따라서, 이 positive lables은 link prediction performance를 평가할때, experimental validations 으로써 볼 수 있다.
> 다시 해석

Feature set 3에서 binary classification models을 구축하기 위해 RF를 사용하는 the proposed framework는 SLAP 보다 더나은 BEDROC과 AUCROC 값을 산출한다. (Table 5)

BEDROC 는 주로 early recognition 관점으로의 ranking systems를 비교할때 사용한다.
> early recognition?
> 수행 전에 알아내는것 같음.
>

This approach는 default coeffiecient parameter를 사용하면서,
더 나은 BEDROC의 AUC 를 산출한다.
이 차이는 Fig.3 에 나와있다.

> BEDROC : 
> The Boltzmann-Enhanced Discrimination of ROC
(BEDROC) Metric.

<hr/>


feature set 2로부터 RF의 feature ranking algorithm을 적용함으로써,
Link prediction을 위한 meta-paths의 중요성을 말 할 수 있다.
Fig 4에서 처럼 Feature imporatance를 dot plot으로 보여질 수 있다.
Two measures evaluated before and after permutations 는 Feature ranking 에 사용된다.
> Random forest에서 전후에 평가한다는 Classification accuracies, Node impurities.
> 두개의 difference 는 평가하는데 사용한다고 했음.

1. Decrease of classification accuracy
2. Decrease of Gini index

비록 two measures는 항상 features가 중요하다고하는데 동의하진 않지만,
우리는 여전히 two measures에 따라 some significantly important meta-paths를 식별할 수 있다.

The top four important meta-paths were C1, C19, C16, and C39 이며,
이 위의 meta-paths들로 연결된 The network nods 들은 compounds, proteins, and GO annotations이다.

the top three important meta-paths는
단지 compounds - proteins 간의 semantic links만 가지고 있다는 것을 눈 여겨볼만 하고,

the top two importance meta-paths는
contain similarity neighboring links를 포함하고 있다는 것도 눈 여겨볼만하다.

그러므로, similarity neighboring links and interaction links를 포함하는 Compounds 와 Proteins 간의 semanitc links 는 CPIs를 예측하는 중요한 역할을 한다.
> Chemical-Protein Interactome (CPI)

<hr/>

predictions를 만들기 전 pre-calculates feature importance 하는 SLAP와 대조적으로, 제안된 Framework는은 feature importance를 평가할 수 있고, 동시에 predictive models을 만들 수 있다.

given topological feature may vary to some extent when
different sets of training data are considered, or when
new links are added into the network as a function of
time.

우리는 data의 다른 sets이 predictive models를 만들기위해 사용되어질때, 
feature importance가 매우 다양할수도 있다는 것을 보이기 위해 실험을 수행핬다.

> predictive models을 만들때 데이터로 학습을 진행하는데, 그 데이터에 따라 model이 바뀌어
> featrue importance를 다르게 측정할 수 있다는 것을 보여주는것 같다. 

우리는 feature 2 에서 임의적으로 선택된 traning sets을 사용하여, 1000개의 RF models를 만들었다.

각 Traning set은 DrugBank로 부터 100 positively labeled links 와 PubChem BioAssay set 100 Negatively labeled links with experimental bioactivity value greater than 10 μM. 

이 다른 models에서의 feature importnace의 변화는 Fig 5에서 보여질 수 있다.
그것은 feature importance가 다른 모델에서 다양하게 존재한다는 것을 명확하게 보여주고있다.

Feature C4 는 the smallest standard deviation(0.828)을 가지고 있고,
Feature C39는 the largest standard deviation(5.537)을 가지고있다.

앞서 언급한 top four importance features의 전부가 very large standard deviations를 가지고 있다는 것은 눈여겨볼만하다.

심지어 그들의 importance는 다른 모델들에서 다양함에도 불구하고, 그것의 mean values는 다른 것들의 평균보다 높다.
> 다양한 모델들에서 importance가 제각각으로 나올 수는 있는데, 이 Top 4의  importance의 평균은 나머지의 평균보다 높다 라는것 같다.

The predictive performances of those 1,000 RF models,
1,000개의 트레이닝 셋에서 포함되지않은, 50 positive labels, 50 negative labels를 임의적으로 선택한 set으로 테스트된,
은 역시 많게 다양했다.

가장높은 F1-score is 0.937이며,
가장낮은 F1-score is 0.667이다.

따라서, Training set의 선택은 성능좋은 predictive machine learning models을 만드는데 또한 중요하다.

<hr/>


####Conclusion

chemical and biological space 분야에서의 지식을 통합한 The semantic network
는 large-scale data mining에 영향을 줄 수 있다.
semantic links의 다른 종류들 중에서, 
drug-target connectivity maps이 drug discovery and development, 특히 drug repositioning and polypharmacology research에서 이득을 취한 이래로, drug-target connectivity maps는 더 넓게 사용되어왔다.

In the present work,
우리는 link prediction을 위한 complex semantic network에서 meta-path-based topological features를 사용하는 최신 machinlearning models의 구축하는 framework를 제안한다.

> 이게 핵심이다

an evolving network 의 links를 포함하는 독립적인 test set에서의 예측성능을 기반으로
Supervised classification models이 강력하다는 것을 보여주었다.

게다가, machine learning models에 내장되어있는 intrinsic feature ranking algorithm은 가장 중요한 topological features를 선택하기위해 사용될수 있음을 보여주었다.
예를들어, drugs and adverse side effects사이의 관계나, proteins and diseases사이의 관계등을 예견할때 사용할 수 있을 것이다.

In the future,
우리는 
1.주어진 prediction task를 위한 가장 관련있는 training set 을 선택하는 방법
2.얼마나 traning set selection이 predictive performance를 향상시킬 수 있는가.
에 대해서 연구할 것이다.

