main = do
    putStrLn "Hello World"
    la <- getLine --leitura de entrada
    let x = read la
    putStrLn(show (x + 1))
    putStrLn(show (qs nums))

nums = [4,5,2,-2,7,9,2,3]

qs [] = []
qs [x] = [x]
qs l =  
    (qs [x | x <- l, x < (head l)] ) ++
    ([x | x <- l, x ==  (head l) ] ) ++
    (qs [x | x <- l, x >  (head l) ] )