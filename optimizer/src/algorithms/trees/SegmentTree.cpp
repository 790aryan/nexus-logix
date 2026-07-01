#include "algorithms/trees/SegmentTree.hpp"

SegmentTree::SegmentTree(
    const std::vector<int>& data
)
{
    n = static_cast<int>(data.size());

    tree.resize(4 * n);

    build(
        1,
        0,
        n - 1,
        data
    );
}

void SegmentTree::build(
    int node,
    int start,
    int end,
    const std::vector<int>& data
)
{
    if(start == end)
    {
        tree[node] = data[start];
        return;
    }

    int mid = (start + end) / 2;

    build(
        node * 2,
        start,
        mid,
        data
    );

    build(
        node * 2 + 1,
        mid + 1,
        end,
        data
    );

    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}

int SegmentTree::query(
    int left,
    int right
) const
{
    return queryInternal(
        1,
        0,
        n - 1,
        left,
        right
    );
}

int SegmentTree::queryInternal(
    int node,
    int start,
    int end,
    int left,
    int right
) const
{
    if(right < start || end < left)
    {
        return 0;
    }

    if(left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int leftSum =
        queryInternal(
            node * 2,
            start,
            mid,
            left,
            right
        );

    int rightSum =
        queryInternal(
            node * 2 + 1,
            mid + 1,
            end,
            left,
            right
        );

    return leftSum + rightSum;
}

void SegmentTree::update(
    int index,
    int value
)
{
    updateInternal(
        1,
        0,
        n - 1,
        index,
        value
    );
}

void SegmentTree::updateInternal(
    int node,
    int start,
    int end,
    int index,
    int value
)
{
    if(start == end)
    {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    if(index <= mid)
    {
        updateInternal(
            node * 2,
            start,
            mid,
            index,
            value
        );
    }
    else
    {
        updateInternal(
            node * 2 + 1,
            mid + 1,
            end,
            index,
            value
        );
    }

    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}