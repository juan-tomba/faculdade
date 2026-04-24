main :: IO()
main = do 
    z <- f 7
    print z

f :: Integer -> IO Integer
f x = do 
    print "Digite um numero"
    ly <- getLine
    let y = read ly
    return (x + y) -- return transforma um inteiro em um IO