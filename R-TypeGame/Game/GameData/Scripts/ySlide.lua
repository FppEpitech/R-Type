for i = 0, getComponentsSize("Position2DComponent") - 1 do
    setComponentFloatArg(i, "Position2DComponent", "y", (getComponentFloatArg(i, "Position2DComponent", "y") + 1))
end
