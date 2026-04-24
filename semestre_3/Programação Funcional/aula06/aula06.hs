main :: IO()
main = do
    print "HW"
    print (safeInc 5 >>= safeInv) -- chamou o safeInv, pq o safeInc deu Just
    print (safeInc 200 >>= safeInv) -- nao chamou o safeInv, pq o safeInc 200 = Nothing
    print $ encontra (>5) [2,3,4,5,7,1,10] -- da certo
    print $ encontra (>15) [2,3,4,5,7,1,10] -- da Nothing
    print $ prodPosNeg [3,4,-2,-5] -- Just -6
    print $ prodPosNeg [3,4,2,5] -- Nothing
    print $ map (\x -> x*x -x + 1) [4,5,2,9] -- usa função labda em vez de criar uma função q vai ser uma vez (tipo, poli = x*x -x + 1)
    print $ prodPosNegSafe [2,4,-5,7]

-- conceito de Monad (muito importante)
-- Monad = um jeito de encadear operações sem você lidar com o contexto
-- maybe é um monad, IO tambem

inv :: (Fractional a) => a -> a
inv x = 1 / x -- nao funciona pra 0

safeInv :: (Fractional a, Eq a) => a -> Maybe a
safeInv 0 = Nothing
safeInv x = Just (1/x)

safeInc :: (Num a, Ord a) => a -> Maybe a
safeInc x
    | x >= 100 = Nothing
    | otherwise = Just (x + 1)

encontra :: (a -> Bool) -> [a] -> Maybe a 
encontra _ [] = Nothing
encontra t (x:xs)
    | t x = Just x
    | otherwise = encontra t xs

prodPosNeg :: (Num a, Ord a) => [a] -> Maybe a -- versao que fariamos em C
prodPosNeg l = case encontra (<0) l of
                    Nothing -> Nothing
                    (Just x) -> case encontra (>0) l of
                                    Nothing -> Nothing
                                    (Just y) -> Just (x * y)

prodPosNegSafe l = 
    (encontra (<0) l >>= \x -> (
        encontra (>0) l >>= \y -> (
            Just (x*y))
    ))

prodPosNegMuitoSafe l = do -- exatamente a mes acoisa que a func de cima (o "do" faz isso)
    x <- encontra (<0)
    y <- encontra (>0)
    Just (x * y)

f l = let n = length l in
    Just (n + 1)

h l = do
    x <- encontra (<0) l
    y <- encontra even l 
    let z = x + y
    w <- encontra (>z) l 
    Just(w + 1)

