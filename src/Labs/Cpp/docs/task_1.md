# Лабораторная работа №1. Оценка трудоемкости блок-схемы, содержащей циклы.

## Блок-схема алгоритма
```mermaid
graph TD
	START(["BEGIN"]) --> A
	A[/"n"/] --> B["s = 0"]
	B --> C{{"i := 5...3*n+2"}}
	C --> D{{"j := 1...2*n*(n+1)"}}
	D --> E["k = 50"]
	E --> F{"k > 33"}
	F --> G["k := k-3"]
	G --> H["s = s + 1"]
	H --> F
	F ---->|")"| D
	D -->|")"| C
	C -->|")"| I[/"s"/]
	I --> END(["END"])
	subgraph GroupA [" "]
		direction LR
		A
		FormA["+1"]
	end
	subgraph GroupB [" "]
		direction LR
		B
		FormB["+1"]
	end
	subgraph GroupC [" "]
		direction LR
		C
		FormC["$$+1+3+\sum_{i=5}^{3n+2}(1+3$$"]
	end
	subgraph GroupD [" "]
		direction LR
		D
		FormD["$$+1+4+\sum_{j=1}^{2n^2+2n}(1+4$$"]
	end
	subgraph GroupE [" "]
		direction LR
		E
		FormE["+1"]
	end
	subgraph GroupF [" "]
		direction LR
		F
		FormF1["k = 50, 47, 44, 41, 38, 35"]
		FormF2["$$+1+\sum_{k'=1}^{6}(1$$"]
	end
	subgraph GroupG [" "]
		direction LR
		G
		FormG["+2"]
	end
	subgraph GroupH [" "]
		direction LR
		H
		FormH["+2"]
	end
	subgraph GroupI [" "]
		direction LR
		I
		FormI["+1"]
	end
	classDef transparent fill:none, stroke:none;
	class GroupA,GroupB,GroupC,GroupD,GroupE,GroupF,GroupG,GroupH,GroupI transparent;
	class FormA,FormB,FormC,FormD,FormE,FormF1,FormF2,FormG,FormH,FormI transparent;
```

## Функция роста трудоемкости алгоритма

Исходное выражение: $$f(n)=1+1+1+3+\sum_{i=5}^{3n+2}(1+3+1+4+\sum_{j=1}^{2n^2+2n}(1+4+1+1+\sum_{k`=1}^{6}(1+2+2)))+1$$
После преобразований: $$f(n)=222n^3+74n^2-121n-11$$

## Точная асимптотическая оценка

По определению: f(n) = $\Theta$(g(n)), если 0 $\le$ C1*g(n) $\le$ f(n) $\le$ C2*g(n).
Предположим, что g(n) = $n^3$, тогда 0 $\le$ C1*$n^3$ $\le$ $222n^3+74n^2-121n-11$ $\le$ C2*$n^3$.
Разделим все части неравенства на $n^3(n^3>0)$, причем C1>0, C2>0:
C1 $\le$ 222+74/n-121/$n^2$-11/$n^3$ $\le$ C2.
C(n)=222+74/n-121/$n^2$-11/$n^3$.
$C1 \in (0, min(C(n))], C2 \in [max(C(n)), +\infty)$.

C1 = 164, C2 = 232,8148148, g(n) = $n^3$.

![График](../images/lab1.png)

f(n) = $\Theta$(g(n)), так как $\lim_{n \to \infty}\frac{222n^3+74n^2-121n-11}{n^3}=\lim_{n \to \infty}(222+74/n-121/n^2-11/n^3)=222$.