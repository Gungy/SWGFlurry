/*
 *	autogen/server/chat/PersistentMessage.h generated by engine3 IDL compiler 0.60
 */

#ifndef PERSISTENTMESSAGE_H_
#define PERSISTENTMESSAGE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif
#endif
namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

#include "server/chat/ChatParameter.h"

#include "server/chat/StringIdChatParameterVector.h"

#include "server/chat/WaypointChatParameter.h"

#include "server/chat/WaypointChatParameterVector.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ManagedObject.h"

#include "system/lang/System.h"

#include "system/util/Vector.h"

namespace server {
namespace chat {

class PersistentMessage : public ManagedObject {
public:
	static const byte NEW;

	static const byte READ;

	static const byte UNREAD;

	PersistentMessage();

	void sendTo(CreatureObject* player, bool sendBody = true);

	StringIdChatParameterVector* getStringIdParameters();

	WaypointChatParameterVector* getWaypointParameters();

	int getMailID();

	unsigned long long getObjectID();

	String getSenderName() const;

	unsigned long long getReceiverObjectID() const;

	byte getStatus() const;

	int getTimeStamp() const;

	UnicodeString getBody() const;

	UnicodeString getSubject() const;

	void setSenderName(const String& name);

	void setReceiverObjectID(unsigned long long oid);

	void setStatus(byte stat);

	void setTimeStamp(int stamp);

	void setBody(const UnicodeString& message);

	void setSubject(const UnicodeString& subj);

	bool isNew() const;

	bool isRead() const;

	bool isUnread() const;

	void addStringIdParameter(StringIdChatParameter& param);

	void addWaypointParameter(WaypointChatParameter& param);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PersistentMessage(DummyConstructorParameter* param);

	virtual ~PersistentMessage();

	friend class PersistentMessageHelper;
};

} // namespace chat
} // namespace server

using namespace server::chat;

namespace server {
namespace chat {

class PersistentMessageImplementation : public ManagedObjectImplementation {
protected:
	String senderName;

	UnicodeString subject;

	UnicodeString body;

	unsigned int timeStamp;

	byte status;

	unsigned long long receiverObjectID;

	StringIdChatParameterVector stringIdParameters;

	WaypointChatParameterVector waypointParameters;

public:
	static const byte NEW;

	static const byte READ;

	static const byte UNREAD;

	PersistentMessageImplementation();

	PersistentMessageImplementation(DummyConstructorParameter* param);

	virtual void sendTo(CreatureObject* player, bool sendBody = true);

	StringIdChatParameterVector* getStringIdParameters();

	WaypointChatParameterVector* getWaypointParameters();

	int getMailID();

	unsigned long long getObjectID();

	String getSenderName() const;

	unsigned long long getReceiverObjectID() const;

	byte getStatus() const;

	int getTimeStamp() const;

	UnicodeString getBody() const;

	UnicodeString getSubject() const;

	void setSenderName(const String& name);

	void setReceiverObjectID(unsigned long long oid);

	void setStatus(byte stat);

	void setTimeStamp(int stamp);

	void setBody(const UnicodeString& message);

	void setSubject(const UnicodeString& subj);

	bool isNew() const;

	bool isRead() const;

	bool isUnread() const;

	void addStringIdParameter(StringIdChatParameter& param);

	void addWaypointParameter(WaypointChatParameter& param);

	WeakReference<PersistentMessage*> _this;

	operator const PersistentMessage*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PersistentMessageImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class PersistentMessage;
};

class PersistentMessageAdapter : public ManagedObjectAdapter {
public:
	PersistentMessageAdapter(PersistentMessage* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendTo(CreatureObject* player, bool sendBody);

	int getMailID();

	unsigned long long getObjectID();

	String getSenderName() const;

	unsigned long long getReceiverObjectID() const;

	byte getStatus() const;

	int getTimeStamp() const;

	UnicodeString getBody() const;

	UnicodeString getSubject() const;

	void setSenderName(const String& name);

	void setReceiverObjectID(unsigned long long oid);

	void setStatus(byte stat);

	void setTimeStamp(int stamp);

	void setBody(const UnicodeString& message);

	void setSubject(const UnicodeString& subj);

	bool isNew() const;

	bool isRead() const;

	bool isUnread() const;

};

class PersistentMessageHelper : public DistributedObjectClassHelper, public Singleton<PersistentMessageHelper> {
	static PersistentMessageHelper* staticInitializer;

public:
	PersistentMessageHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PersistentMessageHelper>;
};

} // namespace chat
} // namespace server

using namespace server::chat;

#endif /*PERSISTENTMESSAGE_H_*/