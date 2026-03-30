main :: IO()
main = do
    print $ 5 +-+-* 7
    print $ (+-+-*) 5 7
    print $ (+) 6 7
    print $ 8 `f12` 5
    print $ mod 13 5
    print $ 13 `mod` 5 -- crase transforma func prefix em infix
    print $ pertence 3 [4,6,2,6,3]
    print $ pertence "Ades" ["José", "Carlos"]
    -- print $ (+1) [f] // não são eq
    print $ f 5
    print $ f 6.2
    print $ fat 10 -- vai usar int, pois o resultado nao passa de int
    print $ fat 100 -- usa Integer
    print $ encontra (<0) [3,4,2,5,6,-8]

-- //CLASSES//
-- Num: Int, Float, Integer, Complex
-- Eq: Int, Float, String, Integer, Complex, Bool
-- Integral: Int, Integer
-- Ord: Int, Float, String, Integer, Bool // vc pode comparar e saber qual é maior
-- Show: Int, Float, String, Integer, Complex, Bool // print só aceita isso
-- Read: Int, Float, Integer, Bool, Char // Podem ser lidos
-- Enum: Char, Int, Integer, Bool
-- Bounded: Int, Char, Bool // Tipos que tem limite

-- por definição, funcoes com letras = prefix
--funcoes com caracteres especiais = infix

-- funcao prefix
f12 x y = x + y

-- infix funcao (entre dois parametros)
x +-+-* y = x + y -- função chama  +-+-*

pertence :: (Eq a) => a -> [a] -> Bool -- Eq = tipos que consigo comparar igualdade
e `pertence`  [] = False
e `pertence` (x:xs)
    |e == x = True
    |otherwise = e `pertence` xs

f :: (Num a) => a -> a -- Não precisamos restringir a função a um tipo, assim, se for chamada com int, vai retornar um int
-- f :: String -> Sring, nem compila
f x = x + 1

fat :: (Integral a) => a -> a -- integer = int sem limite
fat 0 = 1
fat n = n * fat (n-1)

modulo :: (Num a, Ord a) => a -> a -- é um numero que pode ser ordenado
modulo x
    | x > 0 = x
    |Otherwise = -x

encontra :: (a -> Bool) -> [a] -> Maybe a -- Maybe - pode ou nao ter valor
encontra t [] = Nothing
encontra t(xs:xs)
    | t x = Just xs
    | Otherwise = encontra t xs

somatalvez :: Maybe Integer -> Integer -> Maybe Integer
somatalvez Nothing x = Nothing
somatalvez (Just x) y = Just (x * y)