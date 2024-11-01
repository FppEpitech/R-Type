#version 330

in vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float intensity;
out vec4 finalColor;

void main()
{
    vec4 texelColor = texture(texture0, fragTexCoord);
    
    // Achromatopsie (vision in black and white)
    float gray = dot(texelColor.rgb, vec3(0.299, 0.587, 0.114));
    vec3 modifiedColor = vec3(gray);

    finalColor = vec4(mix(texelColor.rgb, modifiedColor, intensity), texelColor.a);
}
