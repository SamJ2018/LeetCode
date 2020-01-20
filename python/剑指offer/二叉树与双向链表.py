# O(n^2)
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def convert(self, root):
        '''

        :param root: TreeNode
        :return: Node
        '''
        if not root:
            return
        self.res = []
        self.pre_order(root)
        for i, node in enumerate(self.res[:-1]):
            node.right = self.res[i + 1]
            self.res[i + 1].left = node
        return self.res[0]

    def pre_order(self, root):
        if not root:
            return
        self.pre_order(root.left)
        self.res.append(root)
        self.pre_order(root.right)






