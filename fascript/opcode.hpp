#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__



namespace fas {
enum class OpCode {
	// ջ����
	LOAD_NULL,			// ����һ����ֵ
	LOAD_BOOL,			// ����һ�� bool ����ֵ�����1�ֽھ���ֵ
	LOAD_INT64,			// ����һ�� int64 ����ֵ�����8�ֽھ���ֵ
	LOAD_FLOAT64,		// ����һ�� double ����ֵ�����8�ֽھ���ֵ
	LOAD_STR16,			// ����һ�� std::string ����ֵ�����2�ֽڳ��ȼ�����
	LOAD_STR32,			// ����һ�� std::string ����ֵ�����4�ֽڳ��ȼ�����
	LOAD_FUNC,			// ����һ����������ֵ�����2�ֽڳ��Ⱥ���id
	LOAD_GLOBAL,		// ����һ��ȫ�ֱ���ֵ�����2�ֽ�ID
	LOAD_MEMBER,		// ����һ�����Ա����ֵ�����2�ֽ�ID
	LOAD_ARGUMENT,		// ����һ������ֵ
	LOAD_VARIABLE,		// ����һ���ֲ�����ֵ
	STORE_GLOBAL,		// �浵һ��ֵ��ȫ�ֱ���
	STORE_MEMBER,		// �浵һ��ֵ�������Ա����
	STORE_ARGUMENT,		// �浵һ��ֵ������
	STORE_VARIABLE,		// �浵һ��ֵ���ֲ�����
	STORE,				// �浵һ��ֵ�����ԣ�

	// ���ʳ�Ա
	LOAD_MEM_ID,		// ��������ĳ���ѻ�ȡID�ĳ�Ա�����2�ֽ�ID	��������Ա����˳��ʾ����LOAD_GLOBAL��LOAD_MEM_ID ����ID
	LOAD_MEM_NAME,		// ��������ĳ����Ա��2->1��					��������Ա����˳��ʾ����LOAD_GLOBAL��LOAD_VARIABLE��LOAD_MEM_NAME
	LOAD_MEM_IMMNUM,	// �����б��ĳ��Ԫ�أ����2�ֽھ���ֵ
	LOAD_MEM_NUM,		// �����б��ĳ��Ԫ�أ�2->1��
	STORE_MEM_ID,		// �浵�����ĳ���ѻ�ȡID�ĳ�Ա�����2�ֽ�ID	�浵�����Ա����˳��ʾ����LOAD_GLOBAL��STORE_MEM_ID ����ID
	STORE_MEM_NAME,		// �浵�����ĳ����Ա��2->1��					�浵�����Ա����˳��ʾ����LOAD_GLOBAL��LOAD_VARIABLE��STORE_MEM_NAME
	STORE_MEM_IMMNUM,	// �浵�б��ĳ��Ԫ�أ����2�ֽھ���ֵ
	STORE_MEM_NUM,		// �浵�б��ĳ��Ԫ�أ�2->1��

	// ����
	NOT,			// �߼�ȡ�� ��1->1��
	AND,			// �߼������㣨2->1��
	OR,				// �߼������㣨2->1��
	ADD,			// ���������㣨2->1��
	SUB,			// ���������㣨2->1��
	MUL,			// ���������㣨2->1��
	DIV,			// ���������㣨2->1��
	MOD,			// ����ȡ�����㣨2->1��

	// ��������
	INVOKE,			// ѹ�뵱ǰִ��λ�ã�4�ֽڣ������ú�����˳�򣺴������ҽ�����ѹջ��Ȼ��ѹ����ID�����INVOKE��
	RET,			// �������أ��ָ��ֳ�
	RET_LOAD,		// �������أ��ָ��ֳ���������һ������ֵ

	OPCODE_END,		// ���һ�������������ھ�̬У����������Ȳ���255
};

static_assert ((int) OpCode::OPCODE_END <= 256, "�������������ܳ�256");
}



#endif //__OPCODE_HPP__
