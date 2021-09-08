#include "Node.h"
#include "Utility.h"

using namespace std;

char Node::computer = ' ';
unsigned int Node::depth = 0;
unsigned int Node::max_depth = 7;

Node::Node(vector<vector<char>> state, unsigned int level, char current_player)
{
    this->level = level;
    this->current_player = current_player;
    this->state = state;
    this->value = TIE;

    if (level > Node::depth)
    {
        Node::depth = level;
    }

    if (win(state))
    {
        if (current_player != Node::computer)
        {
            this->value = WIN - level + 3;
            return;
        }
        this->value = LOST + level - 3;
        return;
    }
    else if (tie(state))
    {
        return;
    }

    if (level == Node::max_depth)
    {
        return;
    }

    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            if (state.at(i).at(j) == ' ')
            {
                vector<vector<char>> new_state = state;
                new_state.at(i).at(j) = current_player;
                Node new_node(new_state, level+1, current_player == 'x' ? 'o' : 'x');
                children.emplace_back(new_node);
            }
        }
    }
}

unsigned int Node::getLevel() const
{
    return level;
}

void Node::calculateValue(int& alphaBeta, const bool first)
{
    if (!children.empty())
    {
        value = children.at(0).value;
        if (current_player == Node::computer)
        {
            for (auto & child : children)
            {
                if (!first && child.value > alphaBeta)
                {
                    value = child.value;
                    return;
                }
                else if (child.value > value)
                {
                    value = child.value;
                }
            }
            if (value < alphaBeta)
            {
                alphaBeta = value;
            }
        }
        else
        {
            for (auto & child : children)
            {
                if (!first && child.value < alphaBeta)
                {
                    value = child.value;
                    return;
                }
                if (child.value < value)
                {
                    value = child.value;
                }
            }
            if (value  > alphaBeta)
            {
                alphaBeta = value;
            }
        }
    }
}

int Node::getValue() const
{
    return value;
}

vector<vector<char>> Node::getState() const
{
    return state;
}

vector<Node> Node::getChildren() const
{
    return children;
}

void Node::getAdresses(vector<Node*>& v, Node* root)
{
    if (!root->children.empty())
    {
        for (auto & i : root->children)
        {
            getAdresses(v, &i);
        }
    }
    v.emplace_back(root);
}
