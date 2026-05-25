main :: IO ()
main = do
    x <- readLn :: IO Int
    y <- readLn :: IO Int
    print $ f $ primosIntervalo x y

-- lista de primos
primos :: [Int]
primos = p [2..]
  where
    p (x:xs) = x : p [y | y <- xs, mod y x /= 0]

-- filtra intervalo
primosIntervalo :: Int -> Int -> [Int]
primosIntervalo x y =
    takeWhile (<= y) (dropWhile (< x) primos)

-- calcula maior intervalo
f :: [Int] -> Int
f (a:b:xs) = max (b - a) (f (b:xs))
f _ = 0