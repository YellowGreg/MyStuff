-- Generate a random number between 1 and 10 
math.randomseed(os.time()) local random_number = math.random(1, 10) 
-- Print the random number 
print("The random number is: " .. random_number) 
-- Check if the number is even or odd 
if random_number % 2 == 0 then 
  print("The number is even.") 
else 
  print("The number is odd.") 
end 
-- Generate a random string 
local letters = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"} 
local random_string = "" for 
i = 1, 10 do 
  local random_index = math.random(1, #letters) 
  random_string = random_string .. letters[random_index] 
end 
-- Print the random string 
print("The random string is: " .. random_string)
