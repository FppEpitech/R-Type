-- for i = 0, getComponentsSize("ColourComponent") - 1 do
--     local r = getComponentIntArg(i, "ColourComponent", "r")
--     local g = getComponentIntArg(i, "ColourComponent", "g")
--     local b = getComponentIntArg(i, "ColourComponent", "b")
--     local a = getComponentIntArg(i, "ColourComponent", "a")
--     if r ~= nil and g ~= nil and b ~= nil and a ~= nil then
--         setComponentIntArg(i, "ColourComponent", "r", r + 1)
--         setComponentIntArg(i, "ColourComponent", "g", g + 2)
--         setComponentIntArg(i, "ColourComponent", "b", b + 3)
--         -- setComponentIntArg(i, "ColourComponent", "a", info + 1)
--     end

-- end

-- rgb for shoot colour components
for i = 0, getComponentsSize("ColourComponent") - 1 do
    local r = getComponentIntArg(i, "ColourComponent", "r")
    local g = getComponentIntArg(i, "ColourComponent", "g")
    local b = getComponentIntArg(i, "ColourComponent", "b")
    local a = getComponentIntArg(i, "ColourComponent", "a")
    local isShoot = getComponentIntArg(i, "ShootComponent", "damage") ~= nil
    if r ~= nil and g ~= nil and b ~= nil and a ~= nil and isShoot then
        setComponentIntArg(i, "ColourComponent", "r", r + 1)
        setComponentIntArg(i, "ColourComponent", "g", g + 2)
        setComponentIntArg(i, "ColourComponent", "b", b + 3)
        -- setComponentIntArg(i, "ColourComponent", "a", info + 1)
    end
end