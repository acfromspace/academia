function InfixToPostfix(str)
    print("Lua Output: ")
    tokens = {}
    tokens1 = {}
    tokens2 = {}
    counter = 1
    counter1 = 1
    counter2 = 2
    for var1 in string.gmatch(str, "%S+") do
        if string.find(var1, "+") then
            tokens1[#tokens1 + 1] = var1
            counter1 = counter1 + 1
            elseif string.find(var1, "-") then
                tokens1[#tokens1 + 1] = var1
                counter1 = counter1 + 1
                elseif string.find(var1, "*") then
                    tokens2[#tokens2 + 1] = var1
                    counter2 = counter2 + 1
                    elseif string.find(var1, "/") then
                        tokens2[#tokens2 + 1] = var1
                        counter2 = counter2 + 1
                        elseif string.find(var1, "%%") then
                            tokens2[#tokens2 + 1] = var1
                            counter2 = counter2 + 1
                            else
                                tokens[#tokens + 1] = var1
                                counter = counter + 1
        end
    end
    for i=1, counter-1, 1 do
        print(tokens[i])
    end
    for j=1, counter2-1, 1 do
        print(tokens2[j])
    end
    for k=1, counter1-1, 1 do
        print(tokens1[k])
    end
end

-- A + B * C + D >>> A B C * + D +
-- for each token in string, do something, return string
