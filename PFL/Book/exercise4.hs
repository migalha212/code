data Arv a = Vazia | No a (Arv a) (Arv a)
    deriving Show

-- 4.1

sumArv :: Num a => Arv a -> a
sumArv Vazia = 0
sumArv (No val left right) = val + sumArv left + sumArv right

-- 4.2

listar :: Arv a -> [a]
listar Vazia = []
listar (No val left right) = listar left ++ [val] ++ listar right

-- 4.3

nivel :: Int -> Arv a -> [a]
nivel _ Vazia = []
nivel 0 (No val _ _) = [val]
nivel a (No _ left right) = (nivel (a - 1) left) ++ (nivel (a - 1) right)

-- 4.4a



-- 4.4b


-- 4.5

mapArv :: (a -> b) -> Arv a -> Arv b
mapArv _ Vazia = Vazia
mapArv f (No val left right) = (No (f val) (mapArv f left) (mapArv f right)) 

data Lista a = Empty | Carruagem a (Lista a)
-- data Maybe a = Nothing | Just a
-- data Bool = False | True

procuraNaLista :: Eq k => Lista (k,v) -> k -> Maybe v
procuraNaLista Empty _ = Nothing
procuraNaLista (Carruagem (chave,valor) cauda) k
    | chave == k = Just valor
    | otherwise = procuraNaLista cauda k

estaNaLista :: Eq k => Lista (k,v) -> k -> Bool
estaNaLista l k = case (procuraNaLista l k) of Nothing -> False
                                               Just _ -> True

ioSucc :: IO ()
ioSucc = do
    putStrLn "Write an integer my man: "
    input <- myGetLine 
    let num = read input :: Int
    putStrLn $ "succ " ++ show (succ num) ++ " ¿"

myGetLine :: IO String
myGetLine = do
    x <- getChar
    if (x == '\n')
        then return []
        else do
            xs <- myGetLine
            return (x:xs)

