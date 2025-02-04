#ifndef MALHAS_H_INCLUDED
#define MALHAS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct Vertice
{
    double x, y, z;

} *VERTICE;

typedef struct Face
{
    vector<int> indice_vertices;

} *FACE;

class Malhas
{
private:
    vector<Vertice> vertices_vetor;
    vector<Face> faces_vetor;

public:
    Malhas()
    {
    }

    string caracteristicasArquivo(const char *nome_arquivo, int num_vertices, int num_faces, int outro)
    {
        string tipo_arquivo;
        ifstream arquivo(nome_arquivo);

        // obter tipo de arquivo
        getline(arquivo, tipo_arquivo);

        // obter tamanho e caracteristicas da malha
        arquivo >> num_vertices >> num_faces >> outro;

        // puts("---------------------- CARACTERISTICAS DA MALHA ----------------------");
        // cout << "Tipo Arquivo: " << tipo_arquivo << endl;
        // cout << "Numero de Vertices: " << num_vertices << endl;
        // cout << "Numero de Faces: " << num_faces << endl;
        // cout << "Outras Caracteristicas: " << outro << endl;
        // puts("----------------------------------------------------------------------");

        return "---------------------- CARACTERISTICAS DA MALHA ----------------------\n"
               "Tipo Arquivo: " +
               tipo_arquivo + "\n" +
               "Numero de Vertices: " + std::to_string(num_vertices) + "\n" +
               "Numero de Faces: " + std::to_string(num_faces) + "\n" +
               "Outras Caracteristicas: " + std::to_string(outro) + "\n"
                                                                    "----------------------------------------------------------------------\n";
    }

    void carregarArquivo(const char *nome_arquivo)
    {
        string tipo_arquivo;
        int num_vertices, num_faces, outro;

        ifstream arquivo(nome_arquivo);

        if (!arquivo)
        {
            cout << "Erro ao abrir o arquivo.1" << endl;
        }
        else
        {
            // obter tipo de arquivo
            getline(arquivo, tipo_arquivo);

            if (tipo_arquivo != "OFF")
            {
                cout << "Erro ao obter formato do arquivo.2" << endl;
            }
            else
            {
                // obter tamanho e caracteristicas da malha
                arquivo >> num_vertices >> num_faces >> outro;

                puts("---------------------- CARACTERISTICAS DA MALHA ----------------------");
                cout << "Tipo Arquivo: " << tipo_arquivo << endl;
                cout << "Numero de Vertices: " << num_vertices << endl;
                cout << "Numero de Faces: " << num_faces << endl;
                cout << "Outras Caracteristicas: " << outro << endl;
                puts("----------------------------------------------------------------------");

                Vertice vertices[num_vertices];

                Face faces[num_faces];

                // ler vertices
                for (int i = 0; i < num_vertices; i++)
                {
                    double x, y, z;

                    arquivo >> x >> y >> z;

                    vertices[i].x = x;
                    vertices[i].y = y;
                    vertices[i].z = z;
                    vertices_vetor.push_back(vertices[i]);
                }

                // ler faces
                for (int j = 0; j < num_faces; ++j)
                {
                    int tipo, v1, v2, v3;
                    arquivo >> tipo >> v1 >> v2 >> v3; // tipo malha, vertice 1 .. 2 .. 3
                    if (tipo == 3)
                    {
                        faces[j].indice_vertices.push_back(v1);
                        faces[j].indice_vertices.push_back(v2);
                        faces[j].indice_vertices.push_back(v3);
                        faces_vetor.push_back(faces[j]);
                    }
                }
            }
            arquivo.close();
        }
    }

    // exibir dados carregados
    void exibirDados(const char *nome_arquivo)
    {
        string caracteristicasArq;

        if (nome_arquivo == "./src/triangles.off")
        {
            ofstream salvar_saida_triangles("triangles_detalhes.txt");

            caracteristicasArq = caracteristicasArquivo(nome_arquivo, vertices_vetor.size(), 0, 0);

            salvar_saida_triangles << caracteristicasArq;

            cout << "Vertices:\n";
            for (int i = 0; i < vertices_vetor.size(); ++i)
            {
                cout << "Vertices " << i << ": ("
                     << vertices_vetor[i].x << ", " << vertices_vetor[i].y << ", " << vertices_vetor[i].z << ")\n";

                salvar_saida_triangles << "Vertices " << i << ": ("
                                       << vertices_vetor[i].x << ", " << vertices_vetor[i].y << ", " << vertices_vetor[i].z << ")\n";
            }

            cout << "\nFaces:\n";
            for (int j = 0; j < faces_vetor.size(); ++j)
            {
                cout << "Face " << j << ": ("
                     << faces_vetor[j].indice_vertices[0] << ", "
                     << faces_vetor[j].indice_vertices[1] << ", "
                     << faces_vetor[j].indice_vertices[2] << ")\n";

                salvar_saida_triangles << "Face " << j << ": ("
                                       << faces_vetor[j].indice_vertices[0] << ", "
                                       << faces_vetor[j].indice_vertices[1] << ", "
                                       << faces_vetor[j].indice_vertices[2] << ")\n";
            }
            salvar_saida_triangles.close();
        }
        else
        {
            ofstream salvar_saida_hand("hand_hybrid_detalhes.txt");

            caracteristicasArq = caracteristicasArquivo(nome_arquivo, vertices_vetor.size(), 0, 0);

            salvar_saida_hand << caracteristicasArq;

            cout << "Vertices:\n";
            for (int i = 0; i < vertices_vetor.size(); ++i)
            {
                cout << "Vertices " << i << ": ("
                     << vertices_vetor[i].x << ", " << vertices_vetor[i].y << ", " << vertices_vetor[i].z << ")\n";

                salvar_saida_hand << "Vertices " << i << ": ("
                                  << vertices_vetor[i].x << ", " << vertices_vetor[i].y << ", " << vertices_vetor[i].z << ")\n";
            }

            cout << "\nFaces:\n";
            for (int j = 0; j < faces_vetor.size(); ++j)
            {
                cout << "Face " << j << ": ("
                     << faces_vetor[j].indice_vertices[0] << ", "
                     << faces_vetor[j].indice_vertices[1] << ", "
                     << faces_vetor[j].indice_vertices[2] << ")\n";

                salvar_saida_hand << "Face " << j << ": ("
                                  << faces_vetor[j].indice_vertices[0] << ", "
                                  << faces_vetor[j].indice_vertices[1] << ", "
                                  << faces_vetor[j].indice_vertices[2] << ")\n";
            }
            salvar_saida_hand.close();
        }
    }
};

#endif