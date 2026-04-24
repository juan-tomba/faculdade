main :: IO()
main = do
    print $ f 5
    print $ f (-1)
    print $ g (-4) (-1) (-5)

baskara a b c
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x1, x2]
    where
        delta = b^2 - 4*a*c
        x = (-b)/(2*a)
        x1 = (-b + sqdelta)/2*a
        x2 = (-b - sqdelta)/2*a
        sqdelta = sqrt delta

safeDiv :: (Fractional a, Eq a) => a -> a -> Either String a
safeDiv _ 0 = Left "Div por zero"
safeDiv x y = Right (x/y)

safeInv :: (Fractional a, Eq a) => a -> Either String a
safeInv 0 = Left "Inv de zero"
safeInv x = Right (1 / x)

f x = do
    a <- safeInv x
    b <- safeDiv a (x + 1)
    let c = a + b 
    d <- safeInv (c + 1)
    return d

g a b c = do 
    x <- baskara a b c
    y <- baskara b c a 
    z <- baskara c a b 
    let w = x + y + z 
    k <- [-w, w]
    return w