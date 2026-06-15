import System.IO
import Data.Ord
import Data.List
 
-- tipo que representa um pais do csv
data Pais = Pais
  { nome        :: String
  , confirmados :: Integer
  , mortes      :: Integer
  , recuperados :: Integer
  , ativos      :: Integer
  } deriving (Show, Read)
 

-- usa foldr pra percorrer a string
quebraEm :: Char -> String -> [String]
quebraEm delim = foldr passo [""]
  where
    passo c (x:xs)
      | c == delim = "" : x : xs
      | otherwise  = (c : x) : xs
    passo _ [] = []
 
-- converte uma linha do csv em um pais
parseLinha :: String -> Pais
parseLinha linha =
  let campos = quebraEm ',' linha
  in Pais
      { nome        = campos !! 0
      , confirmados = read (campos !! 1)
      , mortes      = read (campos !! 2)
      , recuperados = read (campos !! 3)
      , ativos      = read (campos !! 4)
      }
 
-- le e processa todas as linhas do csv
processaPaises :: String -> [Pais]
processaPaises conteudo = map parseLinha $ lines conteudo
 
main :: IO ()
main = do
  -- le os 4 int da entrada
  entrada <- getLine
  let [n1, n2, n3, n4] = map read (words entrada) :: [Integer]
 
  -- abre e le o arquivo csv
  h <- openFile "dados.csv" ReadMode
  conteudo <- hGetContents h
  let paises = processaPaises conteudo
 
  -- soma os ativos dos paises com confirmados >= n1
  print $
    sum $
    map ativos $
    filter ((>= n1) . confirmados) $
    paises
 
  -- dentre os n2 com mais ativos, soma as mortes dos n3 com menos confirmados
  print $
    sum $
    map mortes $
    take (fromIntegral n3) $
    sortBy (comparing confirmados) $
    take (fromIntegral n2) $
    sortBy (flip (comparing ativos)) $
    paises
 
  -- os n4 paises com mais confirmados, em ordem alfabetica
  mapM_ (putStrLn . nome) $
    sortBy (comparing nome) $
    take (fromIntegral n4) $
    sortBy (flip (comparing confirmados)) $
    paises
 
  hClose h