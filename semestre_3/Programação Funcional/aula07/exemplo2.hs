main :: IO()
main = do
    print $ "HW"
    print $ case f (C 50) of
                Bom -> "Ok"
                MaisOuMenos -> "+/-"
                Ruim -> "Bad"
    
    print $ f (F 70)

data Talvez a = Nada | Apenas a 

data Temperatura = C Float | F Float

data Clima = Bom | MaisOuMenos | Ruim 

instance Show Clima where
show Bom = "Vamos para o parque"
show MaisOuMenos = "Talvez um churrasco"
show Ruim = "Netflix com certeza"

f :: Temperatura -> Clima
f (C c)
    | c < 20 = MaisOuMenos 
    | c < 35 = Bom 
    | otherwise = Ruim 

f (F t)
    | t < 50 = MaisOuMenos
    | t < 80 = Bom 
    | otherwise = Ruim