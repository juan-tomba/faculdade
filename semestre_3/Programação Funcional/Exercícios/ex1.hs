main :: IO()
main = do
    a <- readLn :: IO Double -- leitura das entradas (ja faz o casting para double)
    b <- readLn :: IO Double
    c <- readLn :: IO Double
    putStrLn (heron a b c) -- chama a função heron, já printando

heron a b c
    | semi < a = "-" -- casos bases, em que o triângulo não existe
    | semi < b = "-"
    | semi < c = "-"
    | otherwise = show calc -- calcula a área pela fórmula de heron
    where
        semi = (a + b + c)/2 -- semiperímetro
        calc = sqrt $ semi * (semi - a) * (semi - b) * (semi - c)