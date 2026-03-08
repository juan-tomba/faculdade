main = do
    la <- getLine
    let x = read la
    putStrLn(show (x + 1))