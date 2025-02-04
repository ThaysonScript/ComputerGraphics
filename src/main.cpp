#include "Malhas.h"

int main() {
    const char* triangulo = "./src/triangles.off";
    const char* hand = "./src/hand-hybrid.off";

    Malhas malha;
    malha.carregarArquivo(triangulo);
    malha.exibirDados(triangulo);

    Malhas malha2;
    malha2.carregarArquivo(hand);
    malha2.exibirDados(hand);
    
    return 0;
}

/** TRIANGLES.OFF

---------------------- CARACTERISTICAS DA MALHA ----------------------
Tipo Arquivo: OFF
Numero de Vertices: 4
Numero de Faces: 2
Outras Caracteristicas: 0
----------------------------------------------------------------------
Vertices:
Vertices 0: (0, 0, 0)
Vertices 1: (1, 0, 0)
Vertices 2: (0.5, 1, 0)
Vertices 3: (1, 1, 0)

Faces:
Face 0: (0, 1, 2)
Face 1: (1, 3, 2)

 */


/** HAND-HYBRID.OFF
 
---------------------- CARACTERISTICAS DA MALHA ----------------------
Tipo Arquivo: OFF
Numero de Vertices: 6207
Numero de Faces: 4345
Outras Caracteristicas: 0
----------------------------------------------------------------------
Vertices 0: (0.0554, 0.0162, 0)
Vertices 1: (0.0577203, 0.0181563, 0)
Vertices 2: (0.0607045, 0.0195726, 0)
Vertices 3: (0.063874, 0.0205023, 0)
Vertices 4: (0.0667501, 0.0209985, 0)
Vertices 5: (0.0688541, 0.0211143, 0)
Vertices 6: (0.0561857, 0.0150738, 0)
Vertices 7: (0.0581277, 0.0165957, 0)
Vertices 8: (0.0608513, 0.0177669, 0)
Vertices 9: (0.0639482, 0.018641, 0)
Vertices 10: (0.06701, 0.0192715, 0)
Vertices 11: (0.0696283, 0.0197122, 0)
Vertices 12: (0.0568862, 0.0140697, 0)
Vertices 13: (0.0586453, 0.0152246, 0)
Vertices 14: (0.0611999, 0.0161248, 0)
Vertices 15: (0.0642584, 0.0168497, 0)
Vertices 16: (0.0675293, 0.0174786, 0)
Vertices 17: (0.0707209, 0.018091, 0)
Vertices 18: (0.0574939, 0.0131988, 0)
Vertices 19: (0.0591034, 0.0139916, 0)
Vertices 20: (0.0615159, 0.014559, 0)
Vertices 21: (0.0645814, 0.0149981, 0)
Vertices 22: (0.0681498, 0.0154059, 0)
Vertices 23: (0.0720711, 0.0158794, 0)
Vertices 24: (0.058001, 0.0124719, 0)
Vertices 25: (0.0593323, 0.0128449, 0)
Vertices 26: (0.0615649, 0.012982, 0)
Vertices 27: (0.0646937, 0.0129559, 0)
Vertices 28: (0.0687131, 0.0128396, 0)
Vertices 29: (0.0736177, 0.0127062, 0)
Vertices 30: (0.0584, 0.0119, 0)
            ... ... ...
 */