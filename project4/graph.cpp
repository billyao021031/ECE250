#include "graph.hpp"

#include <iostream>
#include <vector>

using namespace std;

graph::graph()
{
    int j = 0;
    while (j < 23133)
    {
        vArr[j] = new vertex;
        vArr[j]->id = j + 1;
        j++;
    }
    vertex_num = 0;
    edge_num = 0;
}

graph::~graph()
{
    int j = 0;
    while (j < 23133)
    {
        delete vArr[j];
        vArr[j] = nullptr;
        j++;
    }
}

bool graph::findVertex(int id)
{
    if (vArr[id - 1]->inserted == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool graph::findCombo(int id_1, int id_2)
{
    for (int i = 0; i < vArr[id_1 - 1]->adj_vertex.size(); i++)
    {
        if (vArr[id_1 - 1]->adj_vertex.at(i) == id_2)
        {
            return true;
        }
    }

    return false;
}

void graph::insertion(int id_1, int id_2, double weight)
{

    vArr[id_1 - 1]->adj_vertex.push_back(id_2);
    vArr[id_1 - 1]->adj_weight.push_back(weight);
    vArr[id_2 - 1]->parent_vertex.push_back(id_1);

    if (vArr[id_1 - 1]->inserted == false)
    {
        vArr[id_1 - 1]->id = id_1;
        vArr[id_1 - 1]->inserted = true;
        vertex_num += 1;
    }

    if (vArr[id_2 - 1]->inserted == false)
    {
        vArr[id_2 - 1]->id = id_2;
        vArr[id_2 - 1]->inserted = true;
        vertex_num += 1;
    }

    edge_num += 1;
}

void graph::print(int id)
{

    for (int i = 0; i < vArr[id - 1]->adj_vertex.size(); i++)
    {
        cout << vArr[id - 1]->adj_vertex.at(i) << " ";
    }
    cout << endl;
}

void graph::deletion(int id)
{

    if (findVertex(id) == false || vertex_num == 0)
    {
        cout << "failure" << endl;
    }
    else
    {
        vArr[id - 1]->adj_vertex.clear();
        vArr[id - 1]->adj_vertex.resize(0);
        vArr[id - 1]->adj_weight.clear();
        vArr[id - 1]->adj_weight.resize(0);
        vArr[id - 1]->inserted = false;

        for (int i = 0; i < vArr[id - 1]->parent_vertex.size(); i++)
        {
            int parent_id = vArr[id - 1]->parent_vertex.at(i);
            for (int j = 0; j < vArr[parent_id - 1]->adj_vertex.size(); j++)
            {
                if (vArr[parent_id - 1]->adj_vertex.at(j) == id)
                {
                    vector<int>::iterator it;
                    it = vArr[parent_id - 1]->adj_vertex.begin();
                    vArr[parent_id - 1]->adj_vertex.erase(it + j);
                }
            }
        }

        vertex_num -= 1;

        cout << "success" << endl;
    }
}

void graph::getMST(int id)
{
    if (findVertex(id) == false || vertex_num == 0)
    {
        cout << "failure" << endl;
        return;
    }
    else
    {
        mst.clear();
        mst.resize(0);
        heap.clear();
        heap.shrink_to_fit();

        vArr[id - 1]->m_key = 0.0;
        heap.push_back(vArr[id - 1]);

        int j = 0;
        while (j < 23133)
        {
            if ((vArr[j] != vArr[id - 1]) && (vArr[j]->inserted == true))
            {
                vArr[j]->m_key = -1;
                heap.push_back(vArr[j]);
            }
            j++;
        }

        heap_builder();

        while (heap.size() != 0)
        {
            vertex *MST = heap[0];
            swap(heap[0], heap.back());
            heap.pop_back();
            heapify(0);

            if (MST->m_key == -1)
            {
                break;
            }

            bool search = false;
            int i = 0;
            while (i < mst.size())
            {
                if (mst[i] == MST->id)
                {
                    search = true;
                }
                i++;
            }

            if (search == false)
            {
                mst.push_back(MST->id);
            }

            for (int k = 0; k < MST->adj_vertex.size(); k++)
            {
                if (MST->adj_weight[k] > vArr[MST->adj_vertex[k] - 1]->m_key)
                {
                    vArr[MST->adj_vertex[k] - 1]->m_key = MST->adj_weight[k];
                    heap_builder();
                }
            }

        }
    }

    cout << mst.size() << endl;
}

int graph::getSize()
{
    cout << "number of vertices is " << vertex_num << endl;
    return vertex_num;
}

void graph::heap_builder()
{
    int j = (heap.size() / 2) - 1;
    while (j >= 0)
    {
        heapify(j);
        j--;
    }
}

void graph::heapify(int id)
{
    int left_hand, right_hand, largest;
    largest = id;
    left_hand = 2 * id + 1;
    right_hand = left_hand + 1;

    if ((left_hand < heap.size()) && ((heap[left_hand]->m_key) > (heap[id]->m_key)))
    {
        largest = left_hand;
    }
    else
    {
        largest = id;
    }

    if ((right_hand < heap.size()) && ((heap[right_hand]->m_key) > (heap[id]->m_key)))
    {
        largest = right_hand;
    }

    if (largest != id)
    {
        swap(heap[id], heap[largest]);

        if (largest < (heap.size() / 2))
        {
            heapify(largest);
        }
    }
}

