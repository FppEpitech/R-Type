#version 330

in vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float intensity;
out vec4 finalColor;

void main()
{
    vec4 texelColor = texture(texture0, fragTexCoord);
    
    // Protanopie
    float red   = dot(texelColor.rgb, vec3(0.567, 0.433, 0.0));
    float green = dot(texelColor.rgb, vec3(0.558, 0.442, 0.0));
    float blue  = dot(texelColor.rgb, vec3(0.0, 0.242, 0.758));

    vec3 modifiedColor = vec3(red, green, blue);
    finalColor = vec4(mix(texelColor.rgb, modifiedColor, intensity), texelColor.a);
}
