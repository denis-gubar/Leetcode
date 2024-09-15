/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode temp(0, 1 << 30);
        PolyNode* node = &temp;
        while(poly1 || poly2)
        {
            if (poly1 && poly2)
            {
                if (poly1->power == poly2->power)
                {
                    if (poly1->coefficient + poly2->coefficient != 0)
                    {
                        node->next = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
                        node = node->next;
                    }
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                    continue;
                }
                if (poly1->power > poly2->power)
                {
                    node->next = new PolyNode(poly1->coefficient, poly1->power);
                    node = node->next;
                    poly1 = poly1->next;
                    continue;
                }
                node->next = new PolyNode(poly2->coefficient, poly2->power);
                node = node->next;
                poly2 = poly2->next;
                continue;
            }
            if (poly1)
            {
                node->next = new PolyNode(poly1->coefficient, poly1->power);
                node = node->next;
                poly1 = poly1->next;
                continue;
            }
            node->next = new PolyNode(poly2->coefficient, poly2->power);
            node = node->next;
            poly2 = poly2->next;
        }
        return temp.next;
    }
};