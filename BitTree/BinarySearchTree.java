/**
 * Created by Wayne on 15/6/7.
 * 二叉查找树的Java实现
 */
public class BitTree {
    public int data;
    public BitTree left;
    public BitTree right;

        public static void main(String args[]) {
        System.out.println("Hello IntellliJ IDEA!");

        BitTree root = new BitTree(5);
        root.insert(3, root);
        root.insert(2, root);
        root.insert(4, root);

        root.insert(7, root);
        root.insert(6, root);
        root.insert(8, root);
        System.out.print("preOrder : ");
        root.preOrder(root);
        System.out.println();
        System.out.print("inOrder : ");
        root.inOrder(root);
        System.out.println();
        System.out.print("postOrder : ");
        root.postOrder(root);
        System.out.println();
        System.out.println("level : " + root.level(root));
        System.out.println("delete : " + root.data);
        root.delete(5, root);
        System.out.print("preOrder : ");
        root.preOrder(root);
        System.out.println();
        System.out.print("inOrder : ");
        root.inOrder(root);
        System.out.println();
    }

    public BitTree() {
    }

    public BitTree(int data) {
        this.data = data;
    }

    public void makeEmpty(BitTree bitTree) {
        if (bitTree != null) {
            makeEmpty(bitTree.left);
            makeEmpty(bitTree.right);
        }
    }

    public BitTree find(int data, BitTree bitTree) {
        if (bitTree == null) {
            return null;
        }
        if (data < bitTree.data) {
            return find(data, bitTree.left);
        } else if (data > bitTree.data) {
            return find(data, bitTree.right);
        } else if (data == bitTree.data) {
            return bitTree;
        } else {
            return null;
        }
    }

    public BitTree findMin(BitTree bitTree) {
        if (bitTree == null) {
            return null;
        }
        if (bitTree.left == null) {
            return bitTree;
        } else {
            return findMin(bitTree.left);
        }
    }

    public BitTree findMax(BitTree bitTree) {
        if (bitTree == null) {
            return null;
        }
        if (bitTree.right == null) {
            return bitTree;
        } else {
            return findMax(bitTree.right);
        }
    }

    public BitTree insert(int data, BitTree bitTree) {
        if (bitTree == null) {
            bitTree = new BitTree();
            bitTree.data = data;
            bitTree.left = null;
            bitTree.right = null;
        } else if (data < bitTree.data) {
            bitTree.left = insert(data, bitTree.left);
        } else if (data > bitTree.data) {
            bitTree.right = insert(data, bitTree.right);
        }
        return bitTree;
    }

    public BitTree delete(int data, BitTree bitTree) {
        if (bitTree == null) {
            return null;
        } else if (data < bitTree.data) {
            bitTree.left = delete(data, bitTree.left);
        } else if (data > bitTree.data) {
            bitTree.right = delete(data, bitTree.right);
        } else if (bitTree.left != null && bitTree.right != null) {
            BitTree temp = findMin(bitTree.right);
            bitTree.data = temp.data;
            bitTree.right = delete(bitTree.data, bitTree.right);
        } else {
            if (bitTree.left == null) {
                bitTree = bitTree.right;
            } else if (bitTree.right == null) {
                bitTree = bitTree.left;
            }
        }
        return bitTree;
    }

    public void preOrder(BitTree bitTree) {
        if (bitTree != null) {
            System.out.print(bitTree.data);
            preOrder(bitTree.left);
            preOrder(bitTree.right);
        }
    }

    public void inOrder(BitTree bitTree) {
        if (bitTree != null) {
            inOrder(bitTree.left);
            System.out.print(bitTree.data);
            inOrder(bitTree.right);
        }
    }

    public void postOrder(BitTree bitTree) {
        if (bitTree != null) {
            postOrder(bitTree.left);
            postOrder(bitTree.right);
            System.out.print(bitTree.data);
        }
    }

    public int level(BitTree root) {
        int left, right;
        if (root == null) {
            return 0;
        } else {
            left = level(root.left);
            right = level(root.right);
            return left > right ? left + 1 : right + 1;
        }
    }
}