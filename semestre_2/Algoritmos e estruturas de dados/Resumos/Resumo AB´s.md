# 🌳 Árvores – Estruturas de Dados

## 📌 Árvore Binária (AB)
Uma **Árvore Binária (AB)** é um conjunto finito de nós tal que:
- Pode ser **vazia**, ou
- Possui um **nó raiz** e duas subárvores:
  - **Subárvore esquerda (TE)**
  - **Subárvore direita (TD)**  
Cada nó pode ter **no máximo dois filhos** (esquerdo e direito).

---

## 🌿 Árvore Estritamente Binária
- Todo nó interno possui **exatamente dois filhos**.
- Nós podem ter:
  - **0 filhos (folhas)** ou  
  - **2 filhos**
- Nunca apenas um filho.

---

## 🌳 Árvore Binária Completa Cheia (ABCC)
Características:
- É **estritamente binária**
- **Todas as folhas estão no mesmo nível**
- Para profundidade `d`:
n = 2^(d+1) - 1

- Altura:
d = log₂(n + 1) - 1

- **Desvantagem:** difícil de manter sempre cheia.

---

## 🌲 Árvore Binária Completa (ABC)
- Todos os níveis anteriores ao último estão **totalmente preenchidos**
- As folhas do último nível ficam **mais à esquerda possível**
- Muito utilizada em implementação com **vetores (heap)**

---

## ⚖️ Árvore Binária Balanceada
- Para **cada nó**:
- A **diferença entre as alturas** das subárvores esquerda e direita é **no máximo 1**
- Garante **boa performance em buscas**

---

## ⚖️✅ Árvore Binária Perfeitamente Balanceada
- Para cada nó:
- A **diferença entre a quantidade de nós** das subárvores esquerda e direita é **no máximo 1**
- Toda árvore perfeitamente balanceada é balanceada,
mas **nem toda balanceada é perfeitamente balanceada**

---

## 📏 Altura de uma Árvore Binária
- **Altura máxima com `n` nós:**  
h_max = n - 1
(árvore degenerada → vira uma lista)

- **Altura mínima:**  
h_min = ⌊log₂(n)⌋

(árvore perfeitamente balanceada)

---

# 🔁 Percursos em Árvores Binárias
Os percursos visitam **cada nó exatamente uma vez**.

---

## ▶️ Pré-Ordem (Pre-order)
Ordem:
1. Visita a **raiz**
2. Percorre a **subárvore esquerda**
3. Percorre a **subárvore direita**

Uso:
- Copiar árvores
- Notação prefixa de expressões

```c
void ab_preordem(NO *raiz) { 
	if (raiz != NULL) { 
	item_imprimir(raiz->item); 
	ab_preordem(raiz->esq); 
	ab_preordem(raiz->dir); 
	} 
}
```

---

## ➡️ Em-Ordem (In-order)
Ordem:
1. Percorre a **subárvore esquerda**
2. Visita a **raiz**
3. Percorre a **subárvore direita**

Uso:
- Em **árvores de busca**, retorna os valores **ordenados**
- Notação infixa de expressões

```c
void ab_emordem(NO *raiz) { 
	if (raiz != NULL) { 
		ab_emordem(raiz->esq); 
		item_imprimir(raiz->item); 
		ab_emordem(raiz->dir); 
	} 
}
```

---

## ◀️ Pós-Ordem (Post-order)
Ordem:
1. Percorre a **subárvore esquerda**
2. Percorre a **subárvore direita**
3. Visita a **raiz**

Uso:
- **Liberação de memória**
- Avaliação de expressões pós-fixa

```c
void ab_posordem(NO *raiz) { 
	if (raiz != NULL) { 
		ab_posordem(raiz->esq); 
		ab_posordem(raiz->dir); 
		item_imprimir(raiz->item); 
	} 
}
```

---

## 🧮 Exemplo de Percursos em Expressões

Expressão:
a + (b * c)

- **Pré-Ordem:** `+ a * b c`
- **Em-Ordem:** `a + (b * c)`
- **Pós-Ordem:** `a b c * +`