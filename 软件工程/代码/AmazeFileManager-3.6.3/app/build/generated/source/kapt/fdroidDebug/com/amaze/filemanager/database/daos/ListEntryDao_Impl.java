package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.utilities.List;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.ArrayList;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class ListEntryDao_Impl implements ListEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<List> __insertionAdapterOfList;

  private final EntityDeletionOrUpdateAdapter<List> __updateAdapterOfList;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByPath;

  public ListEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfList = new EntityInsertionAdapter<List>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR REPLACE INTO `list` (`_id`,`path`) VALUES (nullif(?, 0),?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, List value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
      }
    };
    this.__updateAdapterOfList = new EntityDeletionOrUpdateAdapter<List>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `list` SET `_id` = ?,`path` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, List value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        stmt.bindLong(3, value._id);
      }
    };
    this.__preparedStmtOfDeleteByPath = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM list WHERE path = ?";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final List instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfList.insert(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final List instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfList.handle(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable deleteByPath(final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByPath.acquire();
        int _argIndex = 1;
        if (path == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, path);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDeleteByPath.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<java.util.List<String>> listPaths() {
    final String _sql = "SELECT path FROM list";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<java.util.List<String>>() {
      @Override
      public java.util.List<String> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final java.util.List<String> _result = new ArrayList<String>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final String _item;
            _item = _cursor.getString(0);
            _result.add(_item);
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }
}
