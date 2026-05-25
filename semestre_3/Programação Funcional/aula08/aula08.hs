import System.IO

data Data = Data { ano :: Integer, mes :: Integer, dia :: Integer} -- contrutor tem o msm nome (nao importa)
    deriving (Show, Read)

d1 = Data { ano = 2026, mes = 5, dia = 21}

d2 = Data { ano = 2026, mes = 5, dia = 21}

d3 = d1 { dia = 30} -- igual o d1, mas com o dia 30

d4 = Data { ano = 1990} 

d5 = d4 { mes = 1, dia = 1}

d = [d1,d2,d3,d4,d5]

type Idade = Integer

type Venda = Integer

data Vendedor = Vendedor{
    nome :: [Char],
    cpf:: [Char],
    uf :: [Char],
    aniversario :: Data,
    dependentes :: [Idade],
    vendas :: [Venda]
}

deriving (Show, Read)

main = do
    print d1
    print d3
    print $ mes d1 -- assim que imprime campo (em java seria print d1.mes)
    print $ ano d4 -- podemos printar o ano, pq ta definido
    print d5
    print $ map ano d
    print $
        map dia $
        filter ( (>2000) . ano) $
        d
    -- h <- openFile "vendedores.txt" Readmode
    -- l <- hGetContents h
    -- hClose h
    -- print $ length l (NAO FUNCIONA PQ FECHOU O ARQUIVO \lazy computation)
    -- so colocar o hClose no final (solucao)
    -- `seq` faz ele calcular, independente do lazy computation
    -- print $
    --     sort $
    --     map nome $
    --     filter ((=="SP") . uf) $
    --     vendedores
    -- print $
    --     map nome $
    --     sortBy (comparing uf) $
    --     vendedores
    -- flip serve para inverter 2 parâmetros f(x,y) -> f(y,x)
    