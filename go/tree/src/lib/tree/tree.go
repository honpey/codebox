package tree

import "reflect"

type CBTree struct {
	Root *CBTreeNode
	nodeType reflect.Type
	custom []string
}

type CBTreeNode struct {
	Child *CBTreeNode
	Brother *CBTreeNode
	Tree	*CBTree
	value interface{}
}

func New() *CBTree {
	return new(CBTree).Init()
}

func (t *CBTree) Init() *CBTree {
	tree := &CBTree{
		Root: new(CBTreeNode),
	}
	tree.Root.Tree = tree
	return tree
}



func (t *CBTree)AddChild(parent *CBTreeNode, value interface{}) (*CBTreeNode, error) {
	if parent == nil {
		return nil, nil
	}
	child := new(CBTreeNode)
	child.value = value

	temp := parent.Child
	parent.Child = child
	child.Brother = temp

	return child, nil
}

// 从前序遍历直接从根节点开始就好啦
func (t *CBTree)PreOrderTraval(root *CBTreeNode, f func(interface{})) error {
	if root == nil {
		return nil
	}
	f(root.value)
	curNode := root.Child
	t.PreOrderTraval(curNode, f)

	if curNode != nil {
		curNode := curNode.Brother
		for curNode != nil {
			t.PreOrderTraval(curNode, f)
			curNode = curNode.Brother
		}
	}
	return nil
}

func (t *CBTree)postOrderTravalInternal(root *CBTreeNode, f func(interface{})) error {
	if root == nil {
		return nil
	}
	curNode := root.Child
	t.postOrderTravalInternal(curNode, f)

	if curNode != nil {
		curNode := curNode.Brother
		for curNode != nil {
			t.postOrderTravalInternal(curNode, f)
			curNode = curNode.Brother
		}
	}
	f(root.value)
	return nil
}

func (t *CBTree)PostOrderTravel(root *CBTreeNode, f func(interface{})) error {
	if root == nil {
		return nil
	}
	t.postOrderTravalInternal(root.Child, f)
	f(root.value)
	return nil
}

func MakeTree(topo string) error {
	return nil
}

type test struct {
	name string
}

func main() {
	//t := GetNewTree((*test)(nil))
}
