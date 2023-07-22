-- Comentário de uma linha
--[[ Comentário
    de mais de 
    uma linha ]]

-- Funções

 -- Jeito usual de criar funções
local function drone()
	print("Drone")
end

-- Atribuindo uma função a uma variável
local tello = function()
	print("Tello")
end

-- Chamando as funções
drone() -- Drone
tello() -- Tello

-- Condicionais

local skyrats = true

if skyrats then
	print("Que bom que você faz parte da Skyrats!!")
end

local nota = 7

if nota >= 5 then
	print("Parabéns, você foi aprovado")
elseif nota >= 3 then
	print("Você ainda não foi aprovado, mas pode fazer a rec")
else
	print("Você foi reprovado")
end


-- Tamanho de uma string
local word = "barbara"
print(#word)