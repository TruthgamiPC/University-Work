#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

// declare an interface block; see 'Advanced GLSL' for what these are.

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;


uniform mat4 projection;
//uniform mat3 normalmatrix;
uniform mat4 view;
uniform mat4 model;

void main()
{
    //vec4 position_h = vec4(aPos, 1.0);	// Convert the (x,y,z) position to homogeneous coords (x,y,z,w)
    //mat4 mv_matrix = view * model;

    //vs_out.
    //FragPos = (mv_matrix * position_h).xyz;
    //vs_out.FragPos = vec3(model * vec4(aPos, 1.0));

    //vs_out.Normal = aNormal;
    //vs_out.
    //Normal = normalize(normalmatrix * aNormal);

    //vs_out.Normal = mat3(transpose(inverse(model))) * aNormal;  
    //vs_out.
    //TexCoords = aTexCoords;
    //gl_Position = projection * view * vec4(aPos, 1.0);

    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    TexCoords = aTexCoords;
    
    gl_Position = projection * view * vec4(FragPos, 1.0);
}