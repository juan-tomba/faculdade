import System.IO


-- escrevendo [(string, string)] toda hora.
type Agenda = [(String, String)]

main :: IO ()
main = do
    hSetBuffering stdout NoBuffering 
    loop [] -- chama a func recursiva passando a agenda vazia

loop :: Agenda -> IO ()
loop agenda = do
    eof <- isEOF
    if eof 
        then return () 
        else do
            entrada <- getLine -- le a string digitada
            let tokens = words entrada -- quebra a string nos espacos pra pegar os pedacos

            case tokens of
                -- separa o comando, o nome e o resto
                ("adicionar" : nome : telefones) -> do
                    let telefone = unwords telefones
                    -- varre a lista (tipo o encontra)
                    -- tira o contato se ele ja tiver la
                    let agendaSemAntigo = filter (\(n, _) -> n /= nome) agenda
                    let novaAgenda = (nome, telefone) : agendaSemAntigo
                    loop novaAgenda -- recursao passando a lista atualizada

                ["buscar", nome] -> do
                    case lookup nome agenda of
                        Just telefone -> putStrLn (nome ++ " - " ++ telefone)
                        Nothing       -> putStrLn "Contato nao encontrado."
                    loop agenda

                ["listar"] -> do
                    -- mapM_ eh pra aplicar a funcao em todo mundo da lista e printar
                    mapM_ (\(n, t) -> putStrLn (n ++ " - " ++ t)) agenda
                    loop agenda

                ["remover", nome] -> do
                    -- filtra fora quem a gente quer apagar
                    let novaAgenda = filter (\(n, _) -> n /= nome) agenda
                    -- se o tamanho da lista nao mudou, o contato n existia
                    if length novaAgenda == length agenda
                        then do
                            putStrLn "Contato nao encontrado."
                            loop agenda
                        else do
                            putStrLn "Contato removido."
                            loop novaAgenda

                ["sair"] -> putStrLn "Encerrando."
                _ -> loop agenda