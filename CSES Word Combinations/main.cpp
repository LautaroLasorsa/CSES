#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define esta(x,c) ((c).find(x) != (c).end())
typedef long long intl;
intl MOD = 1e9+7;
vector<int> ary[6000];
intl pos[6000];
// Aca en el namespace esta el algoritmo.
namespace AhoCorasick
{
  typedef char Character; // Tener el typedef permite usar por ejemplo ints si el alfabeto es enorme.

  struct TrieNode
  {
    TrieNode() : wordIndex(-1) {}

    map<Character, TrieNode> children;
    // Indice de la palabra de este nodo. -1 si este nodo no corresponde a una palabra.
    int wordIndex;
    // Siguiente sufijo del string representado por el nodo actual, que es una de las palabras de entrada. Eventualmente NULL si no hay.
    TrieNode *nextDictNode;
    // Siguiente sufijo del string representado por el nodo actual, que es un nodo del Trie. Eventualmente la raiz del Trie.
    // La raiz es el unico con nextTrieNode = NULL
    TrieNode *nextTrieNode;
  };

  struct Trie
  {
    Trie() {}
    vector<int> sizes;
    Trie(const vector<string> &v) // Los string podrian ser un arreglo/vector de Character
    {
      sizes.resize(v.size());
      forn(i,v.size())
      {
        sizes[i] = v[i].size();
        TrieNode *current = &root;
        forn(j, v[i].size())
            current = &current->children[v[i][j]];
        current->wordIndex = i;
      }
      struct Event
      {
        Event(TrieNode *newCurrent, TrieNode *newParent, char newC) : current(newCurrent), parent(newParent), c(newC) {}
        TrieNode *current, *parent;
        Character c;
      };
      root.nextDictNode = root.nextTrieNode = NULL;
      queue<Event> q;
      q.push(Event(&root, NULL, 0));
      while (!q.empty())
      {
        TrieNode *current = q.front().current;
        TrieNode *parent  = q.front().parent;
        char c = q.front().c;
        q.pop();
        if (parent)
        {
          current->nextTrieNode = automataTransition(parent->nextTrieNode, c);
          current->nextDictNode = ( (current->nextTrieNode->wordIndex >= 0) ?
              current->nextTrieNode :
              current->nextTrieNode->nextDictNode
              );
        }
        // Ojo aca con c++11: Sin el & copia en lugar de referenciar, y todo falla horrorosamente.
        for (auto &it : current->children) // Cambiar por la macro forall que itera al map si no hay c++11
          q.push(Event(&it.second, current, it.first));
      }
    }

    TrieNode *automataTransition(TrieNode *currentState, Character x)
    {
      while (currentState && !esta(x, currentState->children)) currentState = currentState->nextTrieNode;
      return currentState ? &currentState->children[x] : &root;
    }

#define REPORT(x,y) cout << x << " " << y << endl

    void reportAllMatches(const string &s)
    {
      // Notar que reporta donde TERMINAN las ocurrencias.
      // Si la palabra que aparece tiene longitud L, la ocurrencia es el rango [pos-L, pos)

      // Llama a REPORT(posicionDondeTerminaLaOcurrencia, indiceDeLaPalabraQueAparece) por cada ocurrencia de alguna palabra en s.
      // Las ocurrencias de palabras que terminan en una misma posicion las va listando de mayor a menor, asi
      // que cuando solamente interesa la ocurrencia mas grande, se puede cambiar el while por mirar solo la primera,
      // y ahi queda lineal garantizado (puede ser mas que lineal esa parte por culpa de tener que iterar todas las ocurrencias
      // para reportarlas, que pueden ser muchas a priori si hay muchos strings uno adentro del otro encajados).

      TrieNode *currentState = &root;
      if (currentState->wordIndex >= 0) REPORT(0,currentState->wordIndex); // Por si esta la palabra vacia... (medio hijoeputa)
      forn(i,s.size())
      {
        TrieNode* matchingState = currentState = automataTransition(currentState, s[i]);
        if (matchingState->wordIndex < 0) matchingState = matchingState->nextDictNode;
        while (matchingState)
        {
         // REPORT(i+1, matchingState->wordIndex);
         // cout<<matchingState->wordIndex;
         // cout<<" >> "<<sizes[matchingState->wordIndex]<<endl;
          ary[i+1].push_back(i+1-sizes[matchingState->wordIndex]);
          matchingState = matchingState->nextDictNode;
        }
      }
    }

    TrieNode root;
  };
};
int main()
{
    string S;
    int N;
    cin>>S>>N;
    vector<string> in(N);
    for(int i = 0;i<N;i++) cin>>in[i];
    AhoCorasick :: Trie T(in);
    T.reportAllMatches(S);
    int l = S.size();
    pos[l] = 1;
    for(int i = l;i>0;i--)
    {
        //cout<<i<<" ::: "<<pos[i]<<endl;
        for(auto k : ary[i])
        {
            pos[k] = (pos[k]+pos[i])%MOD;
        }
    }
    cout<<pos[0]<<endl;
}
