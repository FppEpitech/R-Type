#version 330

in vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float intensity;
out vec4 finalColor;

void main()
{
    vec4 texelColor = texture(texture0, fragTexCoord);
    
    // Tritanomalie
    float red   = dot(texelColor.rgb, vec3(0.0, 0.500, 0.500));
    float green = dot(texelColor.rgb, vec3(0.0, 0.500, 0.500));
    float blue  = dot(texelColor.rgb, vec3(0.300, 0.700, 0.0));

    vec3 modifiedColor = vec3(red, green, blue);
    finalColor = vec4(mix(texelColor.rgb, modifiedColor, intensity), texelColor.a);
}
