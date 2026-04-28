#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

/*
 * PBDS (Ordered Set)
 * find_by_order(k): Returns iterator to kth element (0-indexed)
 * order_of_key(x): Returns number of elements strictly smaller than x
 */
template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
