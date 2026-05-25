main :: IO ()
main = do
    a <- readLn -- leitura entradas
    b <- readLn

    let soma n = sum [d | d <- [1..n-1], n `mod` d == 0] -- soma os divisores

        defeituosos = length [n | n <- [a..b], soma n < n] -- compara e qualifica
        perfeitos   = length [n | n <- [a..b], soma n == n]
        abundantes  = length [n | n <- [a..b], soma n > n]

    print defeituosos
    print perfeitos
    print abundantes