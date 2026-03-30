main :: IO()
main = do
    print (sinal 6)
    print (baskara 2 4 1)
    --print (2^1000)
    print (myLen nums)
    print (mySum nums)
    print (myProd nums)
    print (foldr (+) 0 nums)
    print (foldr (*) 1 nums)
    print("H" ++ "W")
    print (foldr (++) "" strs)

strs =  ["Juan", "Tomba"]

sinal(x)
    | x < 0 = -1
    | x == 0 = 0
    | otherwise = 1 -- Guardas

baskara a b c
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x1, x2] -- Poderia colocar true no lugar de otherwise
    where
        delta = b^2 - 4*a*c
        x = (-b)/(2*a)
        x1 = (-b + sqdelta)/2*a
        x2 = (-b - sqdelta)/2*a
        sqdelta = sqrt delta

nums = [4, 5, 2, 8, 7]
nums2 = (4:(5:(2:(8:(7:[]))))) -- lista de verdade em haskell

myLen [] = 0
myLen (x:xs) = 1 + myLen xs -- x é inutil, podia ser myLen (_:xs)

mySum [] = 0
mySum (x:xs) = x + mySum xs

myProd [] = 1
myProd (x:xs) = x * myProd xs

myMap f [] = []
myMap f (x:xs) = f x:myMap f xs

myFilter t [] = []
myFilter t (x:xs)
    | t x = x:ts
    | otherwise = ts
    where
        ts = myFilter t xs
