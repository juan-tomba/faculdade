## Subclasses

- utiliza "extends" para reaproveitar alguma classe
- @override -> sobrescrever métodos já definidos
- *Hierarquia*

```java
public class Animal{
	public void fazerSom(){
		System.out.println("Som");
	}
}

public class Gato extends Animal{
	public Gato(String nome){
		super(nome);
	}
	
	@override
	public void fazerSom(){
		System.out.println("miau");
	}
}
```

- Todas as classes são subclasses da classe *"Object"*

## MRO - Ordem de resolução de métodos

- É a regra que a linguagem de programação usa para decidir qual método ou atributo será executado quando há **herança múltipla**
- D, B, AB, C, AC, A
