# 📘 Resumo de Lógica – Matemática Discreta

## 1. Conectivos Lógicos
### Operadores
- **AND (∧ / &&)** → verdadeiro apenas se ambos forem verdadeiros.  
- **OR (∨ / ||)** → verdadeiro se pelo menos um for verdadeiro.  
- **XOR (⊕)** → verdadeiro se exatamente um for verdadeiro.  
- **NOT (¬ / !)** → inverte o valor lógico.  

### Tabelas verdade
| Af1 | Af2 | AND | OR | XOR |
|-----|-----|-----|----|-----|
| V   | V   | V   | V  | F   |
| V   | F   | F   | V  | V   |
| F   | V   | F   | V  | V   |
| F   | F   | F   | F  | F   |

NOT:  
- ¬V = F  
- ¬F = V  

### Propriedades Importantes
- **Distributivas:**  
  - a ∧ (b ∨ c) ⇔ (a ∧ b) ∨ (a ∧ c)  
  - a ∨ (b ∧ c) ⇔ (a ∨ b) ∧ (a ∨ c)  

- **De Morgan:**  
  - ¬(a ∨ b) ⇔ (¬a ∧ ¬b)  
  - ¬(a ∧ b) ⇔ (¬a ∨ ¬b)  

- **XOR:**  
  - a ⊕ b ⇔ (a ∨ b) ∧ ¬(a ∧ b)  

- **Dupla Negação:**  
  - ¬(¬a) ⇔ a  

---

## 2. Implicações
- **a ⇒ b**  
  - Só é falso quando a é V e b é F.  

- **a ⇔ b (se e somente se)**  
  - Verdadeiro quando ambos têm o mesmo valor.  

### Propriedades
- (a ⇒ b) ⇔ (¬a ∨ b)  
- (a ⇒ b) ⇔ (¬b ⇒ ¬a) (contrapositiva)  
- (a ⇔ b) ⇔ (b ⇔ a)  

⚠️ Cuidado: a ⇒ b **não** é o mesmo que b ⇒ a (recíproca).  

---

## 3. Quantificadores
- **Universal (∀x)** → “para todo x”.  
- **Existencial (∃x)** → “existe x tal que”.  

### Negação de quantificadores
- ¬(∀x : p(x)) ⇔ ∃x : ¬p(x)  
- ¬(∃x : p(x)) ⇔ ∀x : ¬p(x)  

Exemplo com dois quantificadores:  
- ¬(∀x ∃y : p(x,y)) ⇔ ∃x ∀y : ¬p(x,y)  

---

## 4. Regras de Inferência
### Diretas
1. Se existe x com p(x) falso → ∀x p(x) é falso.  
2. Se existe x com p(x) verdadeiro → ∃x p(x) é verdadeiro.  
3. a, b ⟹ a ∧ b  
4. a ⟹ a ∨ b  
5. a ⇒ b, b ⇒ c ⟹ a ⇒ c (transitividade)  
6. a, a ⇒ b ⟹ b (modus ponens)  
7. a ⇒ b, b ⇒ a ⟹ a ⇔ b  
8. Generalização universal: se q(x) vale para x arbitrário, então ∀x q(x).  

### Indiretas
- **Contrapositiva:** se (¬b ⇒ ¬a), então (a ⇒ b).  
- **Contradição:** se assumir a leva a contradição, então ¬a.  

---

## 5. Indução
### Indução fraca
1. Provar **caso base** (ex: p(1)).  
2. Assumir p(k) e provar p(k+1).  
3. Concluir que p(n) vale para todo n.  

### Indução forte
- Base: p(1) é verdadeiro.  
- Hipótese: p(1)...p(k) verdadeiros.  
- Passo: provar p(k+1).  

### Variante
- Pode começar em qualquer n₀.  

---

## 6. Indução Estrutural
Usada para objetos definidos recursivamente.  
- Exemplo: listas de 0s e 1s com regras de formação.  
- Estratégia:  
  1. Definir p(n) como “após n passos a propriedade vale”.  
  2. Provar por indução normal.  

---

✅ Esse resumo cobre **conectivos, implicações, quantificadores, regras de inferência e indução (normal e estrutural)**.  

