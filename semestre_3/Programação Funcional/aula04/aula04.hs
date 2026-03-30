main :: IO()
main = do 
    print $ f 0 s
    -- print $ f 2 s
    print $ g 0 5
    -- print g s 7 // calcula o s, pq tem q saber se é 0, 1 ou outro
    print $ take 4 [5,6,3,4,s]
    print $ last [4, 6, 2, 3, s, 1]
    print $ take 10 uns
    print $ take 10 $ iteracao (*2) 1
    print $ take 10 l
    print $ take 20 $ primos
    print $ last $ takewhile (<1000) primos
    print $ zipWith (+) [3, 4, 5] [9, 2, 1] -- soma as listas elemento a elemento
    print $ zipWith (*) [3, 4, 5] primos
    print $ take 10 fibs

nums = [3,5,2,1,7,8,5]
-- não funciona
--tmp = nums[1]
--nums[1] = nums[2]
--nums[2] = tmp

-- m = 0
--m = m + 1 (virou um loop, se pedir para imprimir não funciona)
--n = m * 2

a = [1..100000000]
s = sum a -- se vc não usa, ele não faz a conta

f 0 _ = 42
f 1 _ = 101
f x y = x + y

g 0 _ = 42
g 1 _ = 101
g _ x = x

uns = 1:uns -- lista infinita de 1´s

iteracao f x = x:iteracao f (f x) -- vai aplicando f na f

k = [2..] -- iteracao (+1) 2

l = [x | \ <- k, mod x 3 /= 0]

primos = p [2..]
    where
        p (x:xs) = x:p [y | y <- xs, mod y x /= 0] -- lista de numeros primos


myZip _ [] = []
myZip _ _ [] = []
myZip f (x:xs) (y:ys) = f x y : myZip f xs ys

fib 0 = 1
fib 1 = 1
fib n = (fib (n-1) + fib (n - 2))

fibs = 1:1:zipWith (+) fibs (tail fibs) -- fibonacci so que descolado em haskell