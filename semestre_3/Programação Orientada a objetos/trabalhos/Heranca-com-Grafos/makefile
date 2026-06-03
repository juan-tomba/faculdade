JC = javac
JVM = java
JFLAGS = -g

MAIN = Main

CLASSES = \
	Grafo.java \
	GrafoListaAdjacencia.java \
	GrafoMatrizAdjacencia.java \
	GrafoPonderadoMatrizAdjacencia.java \
	Main.java

all: classes

classes: $(CLASSES)
	$(JC) $(JFLAGS) $(CLASSES)

run: classes
	$(JVM) $(MAIN)

clean:
	rm -f *.class