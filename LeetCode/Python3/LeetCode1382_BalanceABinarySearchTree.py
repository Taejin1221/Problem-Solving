# LeetCode1382_BalanceABinarySearchTree.py
class Solution:
	def balanceBST( self, root: TreeNode ) -> TreeNode:
		def inorder( root ):
			if root:
				inorder( root.left )
				datas.append( root.val )
				inorder( root.right )


		def insert( root, val ):
			if root:
				if ( root.val < val ):
					root.right = insert( root.right, val )
				else:
					root.left = insert( root.left, val )

				return root
			else:
				return TreeNode( val )

				
		def balance( root, start, end ):
			if start <= end:
				mid = ( start + end ) // 2

				root = insert( root, datas[mid] )

				root = balance( root, start, mid - 1 )
				root = balance( root, mid + 1, end )

			return root


		datas = []
		inorder( root )

		newRoot = balance( None, 0, ( len( datas ) - 1 ) )

		return newRoot
