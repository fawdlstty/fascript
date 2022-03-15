#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__



namespace fas {
enum class OpCode {
	// ջ����
	LOAD_NULL,				// ����һ����ֵ
	LOAD_BOOL,				// ����һ�� bool ����ֵ�����1�ֽھ���ֵ
	LOAD_INT64,				// ����һ�� int64 ����ֵ�����8�ֽھ���ֵ
	LOAD_FLOAT64,			// ����һ�� double ����ֵ�����8�ֽھ���ֵ
	LOAD_STRING,			// ����һ�� std::string ����ֵ�����4�ֽڳ��ȼ�����
	LOAD_FUNC,				// ����һ����������ֵ�����4�ֽڳ��Ⱥ���id
	LOAD_GLOBAL_VAR,		// ����һ��ȫ�ֱ���ֵ�����4�ֽ�ID
	LOAD_MEMBER_VAR,		// ����һ�����Ա����ֵ�����4�ֽ�ID
	LOAD_ARG_VAR,			// ����һ������ֵ�����4�ֽ�index
	LOAD_LOCAL_VAR,			// ����һ���ֲ�����ֵ�����4�ֽ�ID
	LOAD_VARIABLE,			// ����һ���ֲ�����ֵ
	STORE_GLOBA_VAR,		// �浵һ��ֵ��ȫ�ֱ���
	STORE_MEMBER_VAR,		// �浵һ��ֵ�������Ա����
	STORE_ARG_VAR,			// �浵һ��ֵ������
	STORE_LOCAL_VAR,		// �浵һ��ֵ���ֲ�����
	IGNORE,					// ����һ��ֵ

	// ���ʳ�Ա
	LOAD_MEMBER_ID,			// ��������ĳ���ѻ�ȡID�ĳ�Ա�����2�ֽ�ID	��������Ա����˳��ʾ����LOAD_GLOBAL��LOAD_MEM_ID ����ID
	LOAD_MEMBER_NAME,		// ��������ĳ����Ա��2->1��					��������Ա����˳��ʾ����LOAD_GLOBAL��LOAD_VARIABLE��LOAD_MEM_NAME
	LOAD_MEMBER_IMMNUM,		// �����б��ĳ��Ԫ�أ����4�ֽھ���ֵ
	LOAD_MEMBER_NUM,		// �����б��ĳ��Ԫ�أ�2->1��
	STORE_MEMBER_ID,		// �浵�����ĳ���ѻ�ȡID�ĳ�Ա�����2�ֽ�ID	�浵�����Ա����˳��ʾ����LOAD_GLOBAL��STORE_MEM_ID ����ID
	STORE_MEMBER_NAME,		// �浵�����ĳ����Ա��2->1��					�浵�����Ա����˳��ʾ����LOAD_GLOBAL��LOAD_VARIABLE��STORE_MEM_NAME
	STORE_MEMBER_IMMNUM,	// �浵�б��ĳ��Ԫ�أ����2�ֽھ���ֵ
	STORE_MEMBER_NUM,		// �浵�б��ĳ��Ԫ�أ�2->1��

	// ����
	NOT,					// �߼�ȡ�� ��1->1��
	AND,					// �߼������㣨2->1��
	OR,						// �߼������㣨2->1��
	ADD,					// ���������㣨2->1��
	SUB,					// ���������㣨2->1��
	MUL,					// ���������㣨2->1��
	DIV,					// ���������㣨2->1��
	MOD,					// ����ȡ�����㣨2->1��

	// ��������
	LOAD_POS,				// ѹ��Ŀ��λ�ã�4�ֽڣ�
	GOTO,					// ��ת��ָ��ַ
	RET,					// �������أ����uint8���Ͳ����������ָ��ֳ���������һ������ֵ���൱�ڻ���ջ��������������JMP���ٻָ�ջ����

	OPCODE_END,				// ���һ�������������ھ�̬У����������Ȳ���255
};

static_assert ((int) OpCode::OPCODE_END <= 256, "�������������ܳ�256");
}



#endif //__OPCODE_HPP__
